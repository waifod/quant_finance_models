//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>

#include "asset/asset.hpp"
#include "pricing/model/model.hpp"

class Pricing {
 public:
  void SetModel(std::shared_ptr<Model> model) noexcept;
  double GetAssetPrice(std::shared_ptr<Asset> asset) const noexcept;

 private:
  std::shared_ptr<Model> model_;
};
