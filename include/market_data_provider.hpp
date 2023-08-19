//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>

#include "asset/asset.hpp"

class MarketDataProvider {
 public:
  double GetAssetSpotPrice(std::shared_ptr<Asset> asset) const noexcept;
  double GetAssetVolatility(std::shared_ptr<Asset> asset) const noexcept;
  double GetInterestRate() const noexcept;
};