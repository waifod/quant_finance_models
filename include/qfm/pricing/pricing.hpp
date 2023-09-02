//
// Created by Durante, Matteo on 19/8/23.
//

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
                const asset::AssetType& type) noexcept;
  double GetAssetPrice(std::shared_ptr<asset::Asset> asset) const noexcept;

 private:
  std::unordered_map<std::string, std::shared_ptr<model::Model>> models_;
};

}  // namespace pricing
}  // namespace qfm
