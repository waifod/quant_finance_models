//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>
#include <string>

#include "asset/asset.hpp"
#include "asset/asset_type.hpp"
#include "pricing/model/model.hpp"

class Pricing {
 public:
  void SetModel(std::shared_ptr<Model> model, const AssetType& type) noexcept;
  double GetAssetPrice(std::shared_ptr<Asset> asset) const noexcept;

 private:
  std::unordered_map<std::string, std::shared_ptr<Model>> models_;
};
