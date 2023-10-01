/* 
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

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

}  // namespace asset
}  // namespace qfm
