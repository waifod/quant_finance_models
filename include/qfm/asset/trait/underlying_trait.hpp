/* 
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include <string>

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_trait.hpp"

namespace qfm {
namespace asset {
namespace trait {

class UnderlyingTrait : public AssetTrait {
 public:
  explicit UnderlyingTrait(const Asset& underlying) noexcept;
  explicit UnderlyingTrait(const std::string& asset_ticker) noexcept;
  ~UnderlyingTrait() = default;

  static const std::string Key;
};

}  // namespace trait
}  // namespace asset
}  // namespace qfm
