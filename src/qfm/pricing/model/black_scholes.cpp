//
// Created by Durante, Matteo on 19/8/23.
//

#include "qfm/pricing/model/black_scholes.hpp"

#include <boost/math/distributions/normal.hpp>
#include <chrono>
#include <cmath>
#include <memory>

#include "qfm/asset/asset.hpp"
#include "qfm/asset/trait/expiration_trait.hpp"
#include "qfm/asset/trait/strike_price_trait.hpp"
#include "qfm/market_data_provider.hpp"
#include "qfm/pricing/model/model.hpp"

BlackScholes::BlackScholes(
    std::shared_ptr<MarketDataProvider> market_data_provider) noexcept
    : Model(market_data_provider) {}

double BlackScholes::GetAssetPrice(
    std::shared_ptr<Asset> asset) const noexcept {
  double sigma = market_data_provider_->GetAssetVolatility(asset);
  double spot_price = market_data_provider_->GetAssetSpotPrice(asset);
  double interest_rate = market_data_provider_->GetInterestRate();

  AssetTraitSet traits = asset->GetTraits();
  double strike_price = std::stod(traits.GetValue<StrikePriceTrait>());
  int64_t current_time = 0;  // TODO: Get the current time
  int64_t time_to_maturity =
      std::stoll(traits.GetValue<ExpirationTrait>()) - current_time;

  double d_one = (std::log(spot_price / strike_price) +
                  (interest_rate + (sigma * sigma / 2) * time_to_maturity)) /
                 (sigma * std::sqrt(time_to_maturity));
  double d_two = d_one - sigma * std::sqrt(time_to_maturity);
  auto gaussian = boost::math::normal_distribution(0, 1);
  return cdf(gaussian, d_one) * spot_price -
         cdf(gaussian, d_two) * strike_price *
             std::exp(-interest_rate * time_to_maturity);
}
