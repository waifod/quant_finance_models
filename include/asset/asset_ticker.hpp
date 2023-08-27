#pragma once

#include <string>

class AssetTicker {
 public:
  explicit AssetTicker(const std::string& ticker) noexcept;
  ~AssetTicker() = default;

  bool operator==(const AssetTicker& ticker) const;
  bool operator==(const std::string& ticker) const;
  bool operator!=(const AssetTicker& ticker) const;
  bool operator!=(const std::string& ticker) const;

  operator std::string() const;

 private:
  std::string ticker_;
};