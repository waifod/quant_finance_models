//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>

#include "qfm/asset/asset.hpp"

namespace qfm {

class MarketDataProvider {
 public:
  MarketDataProvider(const double interest_rate) noexcept;
  double GetAssetSpotPrice(const std::string& asset) const noexcept;
  double GetAssetVolatility(const std::string& asset) const noexcept;
  double GetInterestRate() const noexcept;
  void SetInterestRate(const double interest_rate) noexcept;

 private:
  double interest_rate_;
};
}  // namespace qfm
