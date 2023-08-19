//
// Created by Durante, Matteo on 19/8/23.
//

#include "pricing/model/black_scholes.hpp"

#include <cmath>
#include <memory>

#include "market_data_provider.hpp"
#include "pricing/model/model.hpp"

BlackScholes::BlackScholes(std::shared_ptr<MarketDataProvider> market_data_provider)
noexcept
:
Model(market_data_provider) {}

double BlackScholes::GetAssetPrice(std::shared_ptr<Asset> asset) const
noexcept {
  double sigma = market_data_provider_->GetAssetVolatility(asset);
  double spot_price = market_data_provider_->GetAssetSpotPrice(asset);
  double interest_rate = market_data_provider_->GetInterestRate();
  double strike_price = 2.0;  // TODO: Get the strike price
  int time_to_maturity = 2;  // TODO: Get the time to maturity
  double d_one = (std::log(spot_price / strike_price) +
      (interest_rate + (sigma * sigma / 2) * time_to_maturity)) /
      (sigma * std::sqrt(time_to_maturity));
  double d_two = d_one - sigma*std::sqrt(time_to_maturity);
  return sigma;
}