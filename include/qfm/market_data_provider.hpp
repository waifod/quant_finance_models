//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>

#include "qfm/asset/asset.hpp"

namespace qfm {

class MarketDataProvider {
 public:
  double GetAssetSpotPrice(const std::string& asset) const noexcept;
  double GetAssetVolatility(const std::string& asset) const noexcept;
  double GetInterestRate() const noexcept;
};
}  // namespace qfm
