#include "qfm/asset/asset_strike_price.hpp"

#include <string>

namespace qfm {
namespace asset {

AssetStrikePrice::AssetStrikePrice(const double& strike_price) noexcept
    : strike_price_{strike_price} {}

bool AssetStrikePrice::operator==(const double& price) const {
  return strike_price_ == price;
}
bool AssetStrikePrice::operator!=(const double& price) const {
  return strike_price_ != price;
}
bool AssetStrikePrice::operator<=(const double& price) const {
  return strike_price_ <= price;
}
bool AssetStrikePrice::operator>=(const double& price) const {
  return strike_price_ >= price;
}
bool AssetStrikePrice::operator<(const double& price) const {
  return strike_price_ < price;
}
bool AssetStrikePrice::operator>(const double& price) const {
  return strike_price_ > price;
}

AssetStrikePrice::operator double() const { return strike_price_; }

AssetStrikePrice::operator std::string() const {
  return std::to_string(strike_price_);
}

}  // namespace asset
}  // namespace qfm
