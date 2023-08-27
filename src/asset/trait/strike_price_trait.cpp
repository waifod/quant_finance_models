#include "asset/trait/strike_price_trait.hpp"

#include <string>

#include "asset/asset_strike_price.hpp"

StrikePriceTrait::StrikePriceTrait(
    const AssetStrikePrice& strike_price) noexcept
    : AssetTrait(StrikePriceTrait::Key, std::string(strike_price)) {}

StrikePriceTrait::StrikePriceTrait(const double& strike_price) noexcept
    : AssetTrait(StrikePriceTrait::Key, std::to_string(strike_price)) {}

const std::string StrikePriceTrait::Key = "strike_price";
