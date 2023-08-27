#pragma once

#include <string>

#include "asset/asset.hpp"
#include "asset/asset_trait.hpp"

class UnderlyingTrait : public AssetTrait {
 public:
  explicit UnderlyingTrait(const Asset& underlying) noexcept;
  explicit UnderlyingTrait(const std::string& asset_ticker) noexcept;
  ~UnderlyingTrait() = default;

  static const std::string Key;
};
