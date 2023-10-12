/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include "qfm/asset/asset_ticker.hpp"

namespace qfm {

struct AssetQuote {
  double bid;
  double ask;
};

class FinanceApi {
 public:
  FinanceApi() = default;
  virtual ~FinanceApi() = default;
  virtual AssetQuote QueryAssetQuote(
      const asset::AssetTicker& asset) const noexcept = 0;
};

}  // namespace qfm
