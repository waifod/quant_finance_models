/* 
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include "qfm/asset/asset_trait.hpp"

namespace qfm {
namespace asset {

AssetTrait::AssetTrait(const std::string &key,
                       const std::string &value) noexcept
    : key_{key}, value_{value} {}

std::string AssetTrait::GetName() const noexcept { return key_; }
std::string AssetTrait::GetValue() const noexcept { return value_; }

bool AssetTrait::operator==(const AssetTrait &rhs) const {
  return (key_ == rhs.key_) && (value_ == rhs.value_);
}

bool AssetTrait::operator!=(const AssetTrait &rhs) const {
  return (key_ != rhs.key_) || (value_ != rhs.value_);
}

bool AssetTrait::operator>(const AssetTrait &rhs) const {
  return ToString() > rhs.ToString();
}

bool AssetTrait::operator>=(const AssetTrait &rhs) const {
  return ToString() >= rhs.ToString();
}

bool AssetTrait::operator<(const AssetTrait &rhs) const {
  return ToString() < rhs.ToString();
}

bool AssetTrait::operator<=(const AssetTrait &rhs) const {
  return ToString() <= rhs.ToString();
}

AssetTrait::operator std::string() const { return ToString(); }

std::string AssetTrait::ToString() const noexcept {
  return key_ + ":" + value_;
}

const AssetTrait AssetTrait::NO_TRAIT = AssetTrait("", "");

}  // namespace asset
}  // namespace qfm
