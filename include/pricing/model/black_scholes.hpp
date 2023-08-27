//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include "asset/asset.hpp"
#include "pricing/model/model.hpp"
#include "pricing/pricing.hpp"

class BlackScholes : public Model {
 public:
  BlackScholes(
      std::shared_ptr<MarketDataProvider> market_data_provider) noexcept;
  double GetAssetPrice(std::shared_ptr<Asset> asset) const noexcept override;
};