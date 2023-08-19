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
: Model(market_data_provider) {}

double BlackScholes::GetAssetPrice(std::shared_ptr<Asset> asset) const
noexcept {
  double sigma = market_data_provider_->GetAssetVolatility(asset);
  return sigma;
}