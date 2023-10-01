/* 
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include "qfm/asset/asset_strike_price.hpp"

#include <string>

namespace qfm {
namespace asset {

AssetStrikePrice::AssetStrikePrice(double strike_price) noexcept
    : strike_price_{strike_price} {}

bool AssetStrikePrice::operator==(double price) const {
  return strike_price_ == price;
}
bool AssetStrikePrice::operator!=(double price) const {
  return strike_price_ != price;
}
bool AssetStrikePrice::operator<=(double price) const {
  return strike_price_ <= price;
}
bool AssetStrikePrice::operator>=(double price) const {
  return strike_price_ >= price;
}
bool AssetStrikePrice::operator<(double price) const {
  return strike_price_ < price;
}
bool AssetStrikePrice::operator>(double price) const {
  return strike_price_ > price;
}

AssetStrikePrice::operator double() const { return strike_price_; }

AssetStrikePrice::operator std::string() const {
  return std::to_string(strike_price_);
}

}  // namespace asset
}  // namespace qfm
