//
// Created by Durante, Matteo on 19/8/23.
//

#include "qfm/pricing/model/model.hpp"

#include <memory>

namespace qfm {
namespace pricing {
namespace model {

Model::Model(std::shared_ptr<MarketDataProvider> market_data_provider) noexcept
    : market_data_provider_{market_data_provider} {}

}  // namespace model
}  // namespace pricing
}  // namespace qfm
