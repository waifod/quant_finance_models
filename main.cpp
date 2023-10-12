/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include <curl/curl.h>

#include <boost/math/distributions/normal.hpp>
#include <iostream>
#include <memory>
#include <string>

#include "qfm/asset/asset_expiration.hpp"
#include "qfm/asset/asset_strike_price.hpp"
#include "qfm/asset/asset_ticker.hpp"
#include "qfm/asset/asset_trait_set.hpp"
#include "qfm/asset/asset_type.hpp"
#include "qfm/asset/option.hpp"
#include "qfm/asset/trait/expiration_trait.hpp"
#include "qfm/asset/trait/strike_price_trait.hpp"
#include "qfm/finance_api.hpp"
#include "qfm/market_data_provider.hpp"
#include "qfm/pricing/model/black_scholes.hpp"
#include "qfm/pricing/pricing.hpp"
#include "qfm/yahoo_finance_api.hpp"

int main() {
  std::cout << "Hello World!" << std::endl;

  std::cout << "Testing Boost math library" << std::endl;
  auto gaussian = boost::math::normal_distribution(0, 1);
  std::cout << "Outputting random value: " << cdf(gaussian, 2) << std::endl;
  qfm::asset::AssetTicker ticker{"fake_ticker"};
  qfm::asset::AssetType type{qfm::asset::AssetType::call_option};
  qfm::asset::AssetExpiration expiration{1704067200};
  qfm::asset::AssetStrikePrice strike_price{10};
  qfm::asset::AssetTraitSet traits{
      {qfm::asset::trait::ExpirationTrait(expiration),
       qfm::asset::trait::StrikePriceTrait(strike_price)}};
  auto asset = std::make_shared<qfm::asset::Asset>(ticker, type, traits);

  double interest_rate = 1.02;
  std::shared_ptr<qfm::FinanceApi> yahoo_finance_api =
      std::make_shared<qfm::YahooFinanceApi>();
  auto market_data_provider = std::make_shared<qfm::MarketDataProvider>(
      yahoo_finance_api, interest_rate);

  auto amzn_asset_quote = market_data_provider->GetAssetQuote(qfm::asset::AssetTicker("AMZN"));
  std::cout << "Output asset quote of AMZN" << std::endl;
  std::cout << "bid: " << amzn_asset_quote.bid << " and ask: " << amzn_asset_quote.ask << std::endl;

  auto model =
      std::make_shared<qfm::pricing::model::BlackScholes>(market_data_provider);

  qfm::pricing::Pricing pricing;
  pricing.SetModel(model, type);
}
