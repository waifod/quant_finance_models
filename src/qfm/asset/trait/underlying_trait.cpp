#include "qfm/asset/trait/underlying_trait.hpp"

#include <string>

#include "qfm/asset/asset.hpp"

UnderlyingTrait::UnderlyingTrait(const Asset& asset) noexcept
    : AssetTrait(UnderlyingTrait::Key, asset.GetTicker()) {}

UnderlyingTrait::UnderlyingTrait(const std::string& asset_ticker) noexcept
    : AssetTrait(UnderlyingTrait::Key, asset_ticker) {}

const std::string UnderlyingTrait::Key = "underlying";
