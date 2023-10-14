/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include <string>

namespace qfm {
namespace asset {

class AssetStrikePrice {
 public:
  explicit AssetStrikePrice(double strike_price) noexcept;
  ~AssetStrikePrice() = default;

  bool operator==(double price) const;
  bool operator!=(double price) const;
  bool operator<=(double price) const;
  bool operator>=(double price) const;
  bool operator<(double price) const;
  bool operator>(double price) const;

  explicit operator double() const;
  explicit operator std::string() const;

 private:
  const double strike_price_;
};

}  // namespace asset
}  // namespace qfm
