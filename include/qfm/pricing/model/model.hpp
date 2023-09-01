//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>

#include "qfm/asset/asset.hpp"
#include "qfm/market_data_provider.hpp"

class Model {
 public:
  Model() = default;
  Model(std::shared_ptr<MarketDataProvider> market_data_provider) noexcept;
  virtual ~Model() = default;
  virtual double GetAssetPrice(std::shared_ptr<Asset> asset) const noexcept = 0;

 protected:
  std::shared_ptr<MarketDataProvider> market_data_provider_;
};
