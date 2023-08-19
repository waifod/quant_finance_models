//
// Created by Durante, Matteo on 19/8/23.
//

#include "pricing/pricing.hpp"

#include <memory>

#include "asset/asset.hpp"

void Pricing::SetModel(std::shared_ptr<Model> model)
noexcept {
  model_ = model;
}

double Pricing::GetAssetPrice(std::shared_ptr<Asset> asset) const
noexcept {
  return model_->GetAssetPrice(asset);
}
