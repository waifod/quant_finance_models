#pragma once

#include <string>

class AssetType {
 public:
  explicit AssetType(const std::string& type) noexcept;
  ~AssetType() = default;

  bool operator==(const AssetType& type) const;
  bool operator==(const std::string& type) const;
  bool operator!=(const AssetType& type) const;
  bool operator!=(const std::string& type) const;

  operator std::string() const;

  static const AssetType CURRENCY;
  static const AssetType FUTURE;
  static const AssetType CALL_OPTION;
  static const AssetType PUT_OPTION;
  static const AssetType STOCK;

 private:
  std::string type_;
};
