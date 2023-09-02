#include "qfm/asset/asset_expiration.hpp"

namespace qfm {
namespace asset {

AssetExpiration::AssetExpiration(const int64_t& expiration) noexcept
    : expiration_{expiration} {}

AssetExpiration::operator int64_t() const { return expiration_; }

AssetExpiration::operator std::string() const {
  return std::to_string(expiration_);
}

}  // namespace asset
}  // namespace qfm
