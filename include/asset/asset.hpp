#pragma once

#include <string>

class Asset {
 public:
  Asset(std::string ticker) noexcept;
  std::string GetTicker() const noexcept;

 private:
  const std::string ticker_;
};
