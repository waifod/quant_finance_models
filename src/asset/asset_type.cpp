/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include "qfm/asset/asset_type.hpp"

namespace qfm {
namespace asset {

namespace {
const std::string kCurrency{"currency"};
const std::string kBond{"bond"};
const std::string kStock{"stock"};
const std::string kCallOption{"call_option"};
const std::string kPutOption{"put_option"};
const std::string kFuture{"future"};
const std::string kInvalid{"invalid"};
}  // namespace

std::string ToString(const AssetType& type) {
  switch (type) {
    case AssetType::currency:
      return kCurrency;
    case AssetType::bond:
      return kBond;
    case AssetType::stock:
      return kStock;
    case AssetType::call_option:
      return kCallOption;
    case AssetType::put_option:
      return kPutOption;
    case AssetType::future:
      return kFuture;
    default:
      return kInvalid;
  }
}

}  // namespace asset
}  // namespace qfm
