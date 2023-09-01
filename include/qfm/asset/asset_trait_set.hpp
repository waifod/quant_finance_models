#pragma once

#include <set>
#include <unordered_map>

#include "qfm/asset/asset_trait.hpp"

namespace qfm {
namespace asset {

class AssetTraitSet {
 public:
  explicit AssetTraitSet(const std::set<AssetTrait>& traits) noexcept;
  ~AssetTraitSet() = default;

  template <typename Trait>
  bool Has(const Trait& trait) const noexcept {
    return this->Get<Trait>() == trait;
  }

  template <typename Trait>
  bool Has() const noexcept {
    return traits_.find(Trait::Key) != traits_.end();
  };

  template <typename Trait>
  AssetTrait Get() const noexcept {
    auto it = traits_.find(Trait::Key);
    if (it != traits_.end()) {
      return it->second;
    }
    return AssetTrait::NO_TRAIT;
  }

  template <typename Trait>
  std::string GetValue() const noexcept {
    return this->Get<Trait>().GetValue();
  }

 private:
  std::unordered_map<std::string, AssetTrait> traits_;
};

}  // namespace asset
}  // namespace qfm
