#include "pricing/model/null_model.hpp"

#include <iostream>

#include "asset/asset.hpp"
#include "market_data_provider.hpp"
#include "pricing/model/model.hpp"

NullModel::NullModel(
    std::shared_ptr<MarketDataProvider> market_data_provider) noexcept
    : Model(market_data_provider) {}

double NullModel::GetAssetPrice(std::shared_ptr<Asset> asset) const noexcept {
  std::cout << "No pricing model provided. Returning dummy value for asset: " +
                   asset->GetTicker()
            << std::endl;
  return 1.0;
}
