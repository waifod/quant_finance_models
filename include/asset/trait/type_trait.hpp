#pragma once

#include "asset/asset_trait.hpp"
#include "asset/asset_type.hpp"

class TypeTrait : public AssetTrait {
 public:
  explicit TypeTrait(const AssetType& type) noexcept;
  ~TypeTrait() = default;
  static const std::string Key;
};