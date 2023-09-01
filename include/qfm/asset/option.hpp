//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_expiration.hpp"
#include "qfm/asset/asset_strike_price.hpp"
#include "qfm/asset/asset_trait_set.hpp"
#include "qfm/asset/asset_type.hpp"

namespace qfm {
namespace asset {

class Option : public Asset {
 public:
  Option(const std::string& ticker, const AssetType& type,
         const AssetTraitSet& traits) noexcept;
  std::string GetUnderlying() const noexcept;
  AssetStrikePrice GetStrikePrice() const noexcept;
  AssetExpiration GetExpirationDate() const noexcept;
};

}  // namespace trait
}  // namespace asset
