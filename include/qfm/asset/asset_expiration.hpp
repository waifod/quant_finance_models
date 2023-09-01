#pragma once

#include <string>

namespace qfm {
namespace asset {


class AssetExpiration {
 public:
  explicit AssetExpiration(const int64_t& expiration) noexcept;
  ~AssetExpiration() = default;

  bool operator==(const AssetExpiration& expiration) const;
  bool operator==(const int64_t& expiration) const;
  bool operator!=(const AssetExpiration& expiration) const;
  bool operator!=(const int64_t& expiration) const;
  bool operator<=(const AssetExpiration& expiration) const;
  bool operator<=(const int64_t& expiration) const;
  bool operator<(const AssetExpiration& expiration) const;
  bool operator<(const int64_t& expiration) const;
  bool operator>=(const AssetExpiration& expiration) const;
  bool operator>=(const int64_t& expiration) const;
  bool operator>(const AssetExpiration& expiration) const;
  bool operator>(const int64_t& expiration) const;

  operator int64_t() const;
  operator std::string() const;

 private:
  int64_t expiration_;
};

}  // namespace trait
}  // namespace asset
