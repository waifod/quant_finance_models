/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

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
