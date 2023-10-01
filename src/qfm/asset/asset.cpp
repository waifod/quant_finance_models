//
// Created by Durante, Matteo on 19/8/23.
//

#include "qfm/asset/asset.hpp"

#include "qfm/asset/asset_ticker.hpp"
#include "qfm/asset/asset_trait_set.hpp"
#include "qfm/asset/asset_type.hpp"

namespace qfm {
namespace asset {

Asset::Asset(const AssetTicker& ticker, const AssetType& type,
             const AssetTraitSet& traits) noexcept
    : ticker_{ticker}, type_{type}, traits_{traits} {}

AssetTicker Asset::GetTicker() const noexcept { return ticker_; }

AssetType Asset::GetType() const noexcept { return type_; }

AssetTraitSet Asset::GetTraits() const noexcept { return traits_; }

}  // namespace asset
}  // namespace qfm
