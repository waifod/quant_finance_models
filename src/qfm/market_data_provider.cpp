//
// Created by Durante, Matteo on 19/8/23.
//

#include "qfm/market_data_provider.hpp"

#include <memory>

#include "qfm/asset/asset.hpp"

namespace qfm {

double MarketDataProvider::GetAssetSpotPrice(
    std::shared_ptr<asset::Asset> asset) const noexcept {
  return 1.0;
}

double MarketDataProvider::GetAssetVolatility(
    std::shared_ptr<asset::Asset> asset) const noexcept {
  return 1.0;
}

double MarketDataProvider::GetInterestRate() const noexcept { return 1.0; }

}  // namespace qfm
