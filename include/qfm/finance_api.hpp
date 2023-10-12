/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include "qfm/asset/asset_ticker.hpp"

namespace qfm {

class FinanceApi {
 public:
  FinanceApi() = default;
  virtual ~FinanceApi() = default;
  virtual double QueryBidPrice(
      const asset::AssetTicker& asset) const noexcept = 0;
  virtual double QueryAskPrice(
      const asset::AssetTicker& asset) const noexcept = 0;
};

}  // namespace qfm
