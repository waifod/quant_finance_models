//
// Created by Durante, Matteo on 19/8/23.
//

#include "asset.hpp"

#include <string>

Asset::Asset(std::string ticker)
noexcept
: ticker_{std::move(ticker)} {}

std::string Asset::GetTicker() const
noexcept {
  return ticker_;
}