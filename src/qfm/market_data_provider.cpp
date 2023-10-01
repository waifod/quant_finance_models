//
// Created by Durante, Matteo on 19/8/23.
//

#include "qfm/market_data_provider.hpp"

#include <memory>

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_ticker.hpp"

namespace qfm {

MarketDataProvider::MarketDataProvider(const double interest_rate) noexcept
    : interest_rate_{interest_rate} {}

double MarketDataProvider::GetAssetSpotPrice(
    const asset::AssetTicker& asset) const noexcept {
  return 1.0;
}

double MarketDataProvider::GetAssetVolatility(
    const asset::AssetTicker& asset) const noexcept {
  return 1.0;
}

double MarketDataProvider::GetInterestRate() const noexcept {
  return interest_rate_;
}

void MarketDataProvider::SetInterestRate(const double interest_rate) noexcept {
  interest_rate_ = interest_rate;
}

}  // namespace qfm
