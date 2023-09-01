#include "qfm/pricing/model/null_model.hpp"

#include <iostream>

#include "qfm/asset/asset.hpp"
#include "qfm/market_data_provider.hpp"
#include "qfm/pricing/model/model.hpp"

namespace qfm {
namespace pricing {
namespace model {

NullModel::NullModel(
    std::shared_ptr<MarketDataProvider> market_data_provider) noexcept
    : Model(market_data_provider) {}

double NullModel::GetAssetPrice(
    std::shared_ptr<asset::Asset> asset) const noexcept {
  std::cout << "No pricing model provided. Returning dummy value for asset: " +
                   asset->GetTicker()
            << std::endl;
  return 1.0;
}

}  // namespace model
}  // namespace pricing
}  // namespace qfm
