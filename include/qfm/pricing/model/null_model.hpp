/* 
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include "qfm/market_data_provider.hpp"
#include "qfm/pricing/model/model.hpp"

namespace qfm {
namespace pricing {
namespace model {

class NullModel : public Model {
 public:
  NullModel() = default;
  explicit NullModel(
      std::shared_ptr<MarketDataProvider> market_data_provider) noexcept;
  double GetAssetPrice(std::shared_ptr<asset::Asset> asset) const noexcept;
};

}  // namespace model
}  // namespace pricing
}  // namespace qfm
