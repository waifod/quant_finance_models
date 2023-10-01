/* 
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_expiration.hpp"
#include "qfm/asset/asset_strike_price.hpp"
#include "qfm/asset/asset_ticker.hpp"
#include "qfm/asset/asset_trait_set.hpp"
#include "qfm/asset/asset_type.hpp"

namespace qfm {
namespace asset {

class Option : public Asset {
 public:
  AssetTicker GetUnderlying() const noexcept;
  AssetStrikePrice GetStrikePrice() const noexcept;
  AssetExpiration GetExpirationDate() const noexcept;
};

}  // namespace asset
}  // namespace qfm
