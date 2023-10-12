/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include "qfm/asset/asset_ticker.hpp"
#include "qfm/finance_api.hpp"

namespace qfm {

class YahooFinanceApi : public FinanceApi {
 public:
  YahooFinanceApi() = default;
  AssetQuote QueryAssetQuote(
      const asset::AssetTicker& asset_ticker) const noexcept override;
};

}  // namespace qfm
