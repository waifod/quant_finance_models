/* 
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include <string>

#include "qfm/asset/asset_ticker.hpp"
#include "qfm/asset/asset_trait_set.hpp"
#include "qfm/asset/asset_type.hpp"

namespace qfm {
namespace asset {

class Asset {
 public:
  explicit Asset(const AssetTicker& ticker, const AssetType& type,
                 const AssetTraitSet& traits) noexcept;
  AssetTicker GetTicker() const noexcept;
  AssetType GetType() const noexcept;
  AssetTraitSet GetTraits() const noexcept;

 protected:
  AssetTicker ticker_;
  AssetType type_;
  AssetTraitSet traits_;
};

}  // namespace asset
}  // namespace qfm
