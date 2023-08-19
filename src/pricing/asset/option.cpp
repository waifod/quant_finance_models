//
// Created by Durante, Matteo on 19/8/23.
//

#include "asset/option.hpp"

#include "asset/asset.hpp"

Option::Option(std::string ticker, OptionType type, Asset underlying, double strike_price, int expiration_date)
noexcept
: Asset(ticker)
, type_{type}
, underlying_{std::move(underlying)}
, strike_price_{strike_price}
, expiration_date_{expiration_date} {}

OptionType Option::GetType() const
noexcept {
  return type_;
}

Asset Option::GetUnderlying() const
noexcept {
  return underlying_;
}

double Option::GetStrikePrice() const
noexcept {
  return strike_price_;
}

int Option::GetExpirationDate() const
noexcept {
  return expiration_date_;
}
