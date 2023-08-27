#pragma once

#include "asset/asset_expiration.hpp"
#include "asset/asset_trait.hpp"

class ExpirationTrait : public AssetTrait {
 public:
  explicit ExpirationTrait(const AssetExpiration& expiration) noexcept;
  ~ExpirationTrait() = default;

  static const std::string Key;
};
