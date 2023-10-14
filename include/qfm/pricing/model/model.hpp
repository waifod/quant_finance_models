/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include <memory>

#include "qfm/asset/asset.hpp"
#include "qfm/market_data_provider.hpp"

namespace qfm {
namespace pricing {
namespace model {

class Model {
 public:
  Model() = default;
  explicit Model(
      std::shared_ptr<MarketDataProvider> market_data_provider) noexcept;
  virtual ~Model() = default;
  virtual double GetAssetPrice(
      std::shared_ptr<asset::Asset> asset) const noexcept = 0;

 protected:
  std::shared_ptr<MarketDataProvider> market_data_provider_;
};

}  // namespace model
}  // namespace pricing
}  // namespace qfm
