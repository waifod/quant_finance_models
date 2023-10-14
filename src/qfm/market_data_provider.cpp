/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */
#include "qfm/market_data_provider.hpp"

#include <memory>

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_ticker.hpp"

namespace qfm {

MarketDataProvider::MarketDataProvider(std::shared_ptr<FinanceApi> finance_api,
                                       const double interest_rate) noexcept
    : finance_api_{finance_api}, interest_rate_{interest_rate} {}

double MarketDataProvider::GetAssetSpotPrice(
    const asset::AssetTicker& asset_ticker) noexcept {
  return 1.0;
}

AssetQuote MarketDataProvider::GetAssetQuote(
    const asset::AssetTicker& asset_ticker) const noexcept {
  return finance_api_->QueryAssetQuote(asset_ticker);
}

double MarketDataProvider::GetAssetVolatility(
    const asset::AssetTicker& asset_ticker) noexcept {
  return 1.0;
}

double MarketDataProvider::GetInterestRate() const noexcept {
  return interest_rate_;
}
void MarketDataProvider::SetInterestRate(const double interest_rate) noexcept {
  interest_rate_ = interest_rate;
}
}  // namespace qfm
