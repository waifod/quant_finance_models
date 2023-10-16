/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include "qfm/asset/trait/underlying_trait.hpp"

#include <string>

#include "qfm/asset/asset.hpp"

namespace qfm {
namespace asset {
namespace trait {

UnderlyingTrait::UnderlyingTrait(const Asset& asset) noexcept
    : AssetTrait(UnderlyingTrait::Key,
                 static_cast<std::string>(asset.GetTicker())) {}

UnderlyingTrait::UnderlyingTrait(const std::string& asset_ticker) noexcept
    : AssetTrait(UnderlyingTrait::Key, asset_ticker) {}

const std::string UnderlyingTrait::Key = "underlying";

}  // namespace trait
}  // namespace asset
}  // namespace qfm
