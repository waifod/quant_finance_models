//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>

#include "qfm/asset/asset.hpp"

namespace qfm {

class MarketDataProvider {
 public:
  double GetAssetSpotPrice(std::shared_ptr<asset::Asset> asset) const noexcept;
  double GetAssetVolatility(std::shared_ptr<asset::Asset> asset) const noexcept;
  double GetInterestRate() const noexcept;
};
}  // namespace qfm
