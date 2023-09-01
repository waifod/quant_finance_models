#pragma once

#include "qfm/asset/asset_trait.hpp"
#include "qfm/asset/asset_type.hpp"

namespace qfm {
namespace asset {
namespace trait {

class TypeTrait : public AssetTrait {
 public:
  explicit TypeTrait(const AssetType& type) noexcept;
  ~TypeTrait() = default;
  static const std::string Key;
};

}  // namespace trait
}  // namespace asset
}  // namespace qfm
