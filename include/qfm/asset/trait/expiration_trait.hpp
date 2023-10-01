/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include "qfm/asset/asset_expiration.hpp"
#include "qfm/asset/asset_trait.hpp"

namespace qfm {
namespace asset {
namespace trait {

class ExpirationTrait : public AssetTrait {
 public:
  explicit ExpirationTrait(const AssetExpiration& expiration) noexcept;
  ~ExpirationTrait() = default;

  static const std::string Key;
};

}  // namespace trait
}  // namespace asset
}  // namespace qfm
