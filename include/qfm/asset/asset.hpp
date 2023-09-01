#pragma once

#include <string>

#include "qfm/asset/asset_trait_set.hpp"
#include "qfm/asset/asset_type.hpp"

class Asset {
 public:
  explicit Asset(const std::string& ticker, const AssetType& type,
                 const AssetTraitSet& traits) noexcept;
  std::string GetTicker() const noexcept;
  AssetType GetType() const noexcept;
  AssetTraitSet GetTraits() const noexcept;

 protected:
  std::string ticker_;
  AssetType type_;
  AssetTraitSet traits_;
};
