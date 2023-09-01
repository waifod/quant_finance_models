#pragma once

#include <string>

class AssetStrikePrice {
 public:
  explicit AssetStrikePrice(const double& strike_price) noexcept;
  ~AssetStrikePrice() = default;

  bool operator==(const double& price) const;
  bool operator!=(const double& price) const;
  bool operator<=(const double& price) const;
  bool operator>=(const double& price) const;
  bool operator<(const double& price) const;
  bool operator>(const double& price) const;

  operator double() const;
  operator std::string() const;

 private:
  double strike_price_;
};