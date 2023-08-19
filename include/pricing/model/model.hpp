//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>

#include "asset/asset.hpp"
#include "market_data_provider.hpp"

class Model {
 public:
  Model(std::shared_ptr<MarketDataProvider> market_data_provider) noexcept;
  virtual ~Model() = default;
  virtual double GetAssetPrice(std::shared_ptr<Asset> asset) const noexcept = 0;

 protected:
  std::shared_ptr<MarketDataProvider> market_data_provider_;
};