/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#pragma once

#include <memory>
#include <string>

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_type.hpp"
#include "qfm/pricing/model/model.hpp"

namespace qfm {
namespace pricing {

class Pricing {
 public:
  void SetModel(std::shared_ptr<model::Model> model,
                asset::AssetType type) noexcept;
  double GetAssetPrice(std::shared_ptr<asset::Asset> asset) const noexcept;

 private:
  std::unordered_map<asset::AssetType, std::shared_ptr<model::Model>> models_;
};

}  // namespace pricing
}  // namespace qfm
