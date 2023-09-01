#include "asset/asset_expiration.hpp"

AssetExpiration::AssetExpiration(const int64_t& expiration) noexcept
    : expiration_{expiration} {}

AssetExpiration::operator int64_t() const { return expiration_; }

AssetExpiration::operator std::string() const {
  return std::to_string(expiration_);
}