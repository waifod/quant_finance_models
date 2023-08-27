//
// Created by Durante, Matteo on 19/8/23.
//

#include "asset/asset.hpp"

#include "asset/asset_trait_set.hpp"
#include "asset/asset_type.hpp"

Asset::Asset(const std::string& ticker, const AssetType& type,
             const AssetTraitSet& traits) noexcept
    : ticker_{ticker}, type_{type}, traits_{traits} {}

std::string Asset::GetTicker() const noexcept { return ticker_; }

AssetType Asset::GetType() const noexcept { return type_; }

AssetTraitSet Asset::GetTraits() const noexcept { return traits_; }
