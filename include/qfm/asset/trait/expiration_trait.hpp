#pragma once

#include "qfm/asset/asset_expiration.hpp"
#include "qfm/asset/asset_trait.hpp"

class ExpirationTrait : public AssetTrait {
 public:
  explicit ExpirationTrait(const AssetExpiration& expiration) noexcept;
  ~ExpirationTrait() = default;

  static const std::string Key;
};
