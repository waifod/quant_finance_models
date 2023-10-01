/* 
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include "qfm/asset/asset_trait_set.hpp"

#include <set>

#include "qfm/asset/asset_trait.hpp"

namespace qfm {
namespace asset {

AssetTraitSet::AssetTraitSet(const std::set<AssetTrait>& traits) noexcept {
  for (const auto& trait : traits) {
    traits_.insert(std::make_pair(trait.GetName(), trait));
  }
}

}  // namespace asset
}  // namespace qfm
