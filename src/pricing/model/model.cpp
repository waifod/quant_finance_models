//
// Created by Durante, Matteo on 19/8/23.
//

#include "pricing/model/model.hpp"

#include <memory>

Model::Model(std::shared_ptr<MarketDataProvider> market_data_provider)
noexcept
: market_data_provider_{market_data_provider} {}