#include "qfm/asset/trait/strike_price_trait.hpp"

#include <string>

#include "qfm/asset/asset_strike_price.hpp"

namespace qfm {
namespace asset {
namespace trait {

StrikePriceTrait::StrikePriceTrait(
    const AssetStrikePrice& strike_price) noexcept
    : AssetTrait(StrikePriceTrait::Key, std::string(strike_price)) {}

StrikePriceTrait::StrikePriceTrait(double strike_price) noexcept
    : AssetTrait(StrikePriceTrait::Key, std::to_string(strike_price)) {}

const std::string StrikePriceTrait::Key = "strike_price";

}  // namespace trait
}  // namespace asset
}  // namespace qfm
