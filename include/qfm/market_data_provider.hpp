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
                              double interest_rate) noexcept;
  static double GetAssetSpotPrice(
      const asset::AssetTicker& asset_ticker) noexcept;
  AssetQuote GetAssetQuote(
      const asset::AssetTicker& asset_ticker) const noexcept;
  static double GetAssetVolatility(const asset::AssetTicker& asset) noexcept;
  double GetInterestRate() const noexcept;
  void SetInterestRate(double interest_rate) noexcept;

 private:
  std::shared_ptr<FinanceApi> finance_api_;
  double interest_rate_;
};
}  // namespace qfm
