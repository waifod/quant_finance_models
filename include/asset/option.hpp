//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include "asset/asset.hpp"

enum class OptionType { CALL, PUT };

class Option : public Asset {
 public:
  Option(std::string ticker, OptionType type, Asset underlying, double strike_price, int expiration_date) noexcept;
  OptionType GetType() const noexcept;
  Asset GetUnderlying() const noexcept;
  double GetStrikePrice() const noexcept;
  int GetExpirationDate() const noexcept;

 private:
  OptionType type_;
  Asset underlying_;
  double strike_price_;
  int expiration_date_;
};