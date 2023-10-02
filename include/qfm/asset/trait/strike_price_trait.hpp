/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include "qfm/asset/asset_strike_price.hpp"
#include "qfm/asset/asset_trait.hpp"

namespace qfm {
namespace asset {
namespace trait {

class StrikePriceTrait : public AssetTrait {
 public:
  explicit StrikePriceTrait(const AssetStrikePrice& strike_price) noexcept;
  explicit StrikePriceTrait(double strike_price) noexcept;
  ~StrikePriceTrait() = default;
  static const std::string Key;
};

}  // namespace trait
}  // namespace asset
}  // namespace qfm
