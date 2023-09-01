//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include "qfm/asset/asset.hpp"
#include "qfm/pricing/model/model.hpp"
#include "qfm/pricing/pricing.hpp"

namespace qfm {
namespace pricing {
namespace model {

class BlackScholes : public Model {
 public:
  explicit BlackScholes(
      std::shared_ptr<MarketDataProvider> market_data_provider) noexcept;
  double GetAssetPrice(std::shared_ptr<asset::Asset> asset) const noexcept override;
};

}  // namespace model
}  // namespace pricing
}  // namespace qfm
