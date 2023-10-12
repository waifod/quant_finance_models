/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */
#pragma once
#include <memory>

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_ticker.hpp"
#include "qfm/finance_api.hpp"

namespace qfm {

class MarketDataProvider {
 public:
  explicit MarketDataProvider(std::shared_ptr<FinanceApi> finance_api,
                              const double interest_rate) noexcept;
  double GetAssetSpotPrice(
      const asset::AssetTicker& asset_ticker) const noexcept;
  AssetQuote GetAssetQuote(
      const asset::AssetTicker& asset_ticker) const noexcept;
  double GetAssetVolatility(const asset::AssetTicker& asset) const noexcept;
  double GetInterestRate() const noexcept;
  void SetInterestRate(const double interest_rate) noexcept;

 private:
  std::shared_ptr<FinanceApi> finance_api_;
  double interest_rate_;
};
}  // namespace qfm
