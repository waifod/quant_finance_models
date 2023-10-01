/* 
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include "qfm/pricing/model/black_scholes.hpp"

#include <boost/math/distributions/normal.hpp>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_ticker.hpp"
#include "qfm/asset/asset_type.hpp"
#include "qfm/asset/trait/expiration_trait.hpp"
#include "qfm/asset/trait/strike_price_trait.hpp"
#include "qfm/asset/trait/underlying_trait.hpp"
#include "qfm/market_data_provider.hpp"
#include "qfm/pricing/model/model.hpp"

namespace qfm {
namespace pricing {
namespace model {

BlackScholes::BlackScholes(
    std::shared_ptr<MarketDataProvider> market_data_provider) noexcept
    : Model(market_data_provider) {}

double BlackScholes::GetAssetPrice(
    std::shared_ptr<asset::Asset> asset) const noexcept {
  asset::AssetType asset_type = asset->GetType();
  if (asset_type != asset::AssetType::call_option &&
      asset_type != asset::AssetType::put_option) {
    std::cout << "Black-Scholes model received asset of invalid type "
              << ToString(asset_type) << ", returning dummy price" << std::endl;
    return -1;
  }

  asset::AssetTraitSet traits = asset->GetTraits();
  asset::AssetTicker underlying =
      asset::AssetTicker(traits.GetValue<asset::trait::UnderlyingTrait>());
  double strike_price =
      std::stod(traits.GetValue<asset::trait::StrikePriceTrait>());
  int64_t expiration =
      std::stoll(traits.GetValue<asset::trait::ExpirationTrait>());

  double sigma = market_data_provider_->GetAssetVolatility(underlying);
  double spot_price = market_data_provider_->GetAssetSpotPrice(underlying);
  double interest_rate = market_data_provider_->GetInterestRate();

  // This depends on the system_clock epoch being the Unix epoch, which is true
  // from C++20 and the de facto standard in the preceding versions
  int64_t current_time =
      std::chrono::duration_cast<std::chrono::seconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();
  int64_t time_to_maturity = expiration - current_time;

  double d_one = (std::log(spot_price / strike_price) +
                  (interest_rate + (sigma * sigma / 2) * time_to_maturity)) /
                 (sigma * std::sqrt(time_to_maturity));
  double d_two = d_one - sigma * std::sqrt(time_to_maturity);
  auto gaussian = boost::math::normal_distribution(0, 1);

  if (asset_type == asset::AssetType::call_option) {
    return cdf(gaussian, d_one) * spot_price -
           cdf(gaussian, d_two) * strike_price *
               std::exp(-interest_rate * time_to_maturity);
  }

  return cdf(gaussian, -d_two) * strike_price *
             std::exp(-interest_rate * time_to_maturity) -
         cdf(gaussian, -d_one) * spot_price;
}

}  // namespace model
}  // namespace pricing
}  // namespace qfm
