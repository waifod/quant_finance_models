/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include <string>

namespace qfm {
namespace asset {

class AssetTrait {
 public:
  virtual ~AssetTrait() = default;

  std::string GetName() const noexcept;
  std::string GetValue() const noexcept;

  bool operator==(const AssetTrait& trait) const;
  bool operator!=(const AssetTrait& trait) const;
  bool operator>(const AssetTrait& trait) const;
  bool operator>=(const AssetTrait& trait) const;
  bool operator<(const AssetTrait& trait) const;
  bool operator<=(const AssetTrait& trait) const;

  operator std::string() const;

  static const AssetTrait NO_TRAIT;

 protected:
  explicit AssetTrait(const std::string& key,
                      const std::string& value) noexcept;
  std::string ToString() const noexcept;

 private:
  std::string key_;
  std::string value_;
};

}  // namespace asset
}  // namespace qfm
