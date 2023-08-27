//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include "asset/asset.hpp"
#include "asset/asset_expiration.hpp"
#include "asset/asset_strike_price.hpp"
#include "asset/asset_trait_set.hpp"
#include "asset/asset_type.hpp"

class Option : public Asset {
 public:
  Option(const std::string& ticker, const AssetType& type,
         const AssetTraitSet& traits) noexcept;
  std::string GetUnderlying() const noexcept;
  AssetStrikePrice GetStrikePrice() const noexcept;
  AssetExpiration GetExpirationDate() const noexcept;
};