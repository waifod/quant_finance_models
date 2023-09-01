//
// Created by Durante, Matteo on 19/8/23.
//

#include "qfm/asset/option.hpp"

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_expiration.hpp"
#include "qfm/asset/asset_strike_price.hpp"
#include "qfm/asset/asset_type.hpp"
#include "qfm/asset/trait/expiration_trait.hpp"
#include "qfm/asset/trait/strike_price_trait.hpp"
#include "qfm/asset/trait/type_trait.hpp"
#include "qfm/asset/trait/underlying_trait.hpp"

Option::Option(const std::string& ticker, const AssetType& type,
               const AssetTraitSet& traits) noexcept
    : Asset(ticker, type, traits) {}

std::string Option::GetUnderlying() const noexcept {
  return traits_.GetValue<UnderlyingTrait>();
}

AssetStrikePrice Option::GetStrikePrice() const noexcept {
  return AssetStrikePrice(std::stod(traits_.GetValue<StrikePriceTrait>()));
}

AssetExpiration Option::GetExpirationDate() const noexcept {
  return AssetExpiration(std::stoll(traits_.GetValue<ExpirationTrait>()));
}
