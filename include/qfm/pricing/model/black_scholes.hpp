//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include "qfm/asset/asset.hpp"
#include "qfm/pricing/model/model.hpp"
#include "qfm/pricing/pricing.hpp"

class BlackScholes : public Model {
 public:
  BlackScholes(
      std::shared_ptr<MarketDataProvider> market_data_provider) noexcept;
  double GetAssetPrice(std::shared_ptr<Asset> asset) const noexcept override;
};
