//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>

#include "asset.hpp"

class Pricing {
 public:
  void SetModel(std::shared_ptr<Model> model) noexcept;
  double GetAssetPrice(Asset asset) const noexcept;

 private:
  std::shared_ptr<Model> model_;
};