//
// Created by Durante, Matteo on 19/8/23.
//

#include "qfm/pricing/pricing.hpp"

#include <memory>
#include <string>

#include "qfm/asset/asset.hpp"
#include "qfm/pricing/model/model.hpp"
#include "qfm/pricing/model/null_model.hpp"

void Pricing::SetModel(std::shared_ptr<Model> model,
                       const AssetType& type) noexcept {
  models_.insert(std::make_pair(type, model));
}

double Pricing::GetAssetPrice(std::shared_ptr<Asset> asset) const noexcept {
  auto it = models_.find(asset->GetType());
  if (it != models_.end()) {
    return it->second->GetAssetPrice(asset);
  }
  return NullModel().GetAssetPrice(asset);
}
