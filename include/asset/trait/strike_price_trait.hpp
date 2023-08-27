#pragma once

#include "asset/asset_strike_price.hpp"
#include "asset/asset_trait.hpp"

class StrikePriceTrait : public AssetTrait {
 public:
  explicit StrikePriceTrait(const AssetStrikePrice& strike_price) noexcept;
  explicit StrikePriceTrait(const double& strike_price) noexcept;
  ~StrikePriceTrait() = default;
  static const std::string Key;
};