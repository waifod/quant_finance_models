/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include <algorithm>
#include <boost/program_options.hpp>
#include <iostream>
#include <memory>
#include <string>

#include <qfm/asset/asset_expiration.hpp>
#include <qfm/asset/asset_strike_price.hpp>
#include <qfm/asset/asset_ticker.hpp>
#include <qfm/asset/asset_trait_set.hpp>
#include <qfm/asset/asset_type.hpp>
#include <qfm/asset/option.hpp>
#include <qfm/asset/trait/expiration_trait.hpp>
#include <qfm/asset/trait/strike_price_trait.hpp>
#include <qfm/finance_api.hpp>
#include <qfm/market_data_provider.hpp>
#include <qfm/pricing/model/black_scholes.hpp>
#include <qfm/pricing/pricing.hpp>
#include <qfm/yahoo_finance_api.hpp>

int main(int argc, char* argv[]) {
  boost::program_options::options_description options_description(
      "Quant Finance Models (QFM) CLI utility");

  std::string input_asset_ticker;
  int input_expiration;
  double input_strike_price;

  try {
    // clang-format off
    options_description.add_options()
        ("help,h", "print usage message")
        ("asset,a", boost::program_options::value<std::string>(&input_asset_ticker), "asset ticket")
        ("expiration,e", boost::program_options::value<int>(&input_expiration), "expiration date")
        ("strike-price,s", boost::program_options::value<double>(&input_strike_price), "strike price");
    // clang-format on

    boost::program_options::variables_map variables_map;
    boost::program_options::store(boost::program_options::parse_command_line(
                                      argc, argv, options_description),
                                  variables_map);

    if (static_cast<bool>(variables_map.count("help"))) {
      std::cout << options_description;
      return 0;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
  }

  qfm::asset::AssetTicker asset_ticker{input_asset_ticker};
  qfm::asset::AssetType asset_type{qfm::asset::AssetType::call_option};
  qfm::asset::AssetExpiration asset_expiration{input_expiration};
  qfm::asset::AssetStrikePrice strike_price{input_strike_price};
  qfm::asset::AssetTraitSet traits{
      {qfm::asset::trait::ExpirationTrait(asset_expiration),
       qfm::asset::trait::StrikePriceTrait(strike_price)}};
  auto asset =
      std::make_shared<qfm::asset::Asset>(asset_ticker, asset_type, traits);

  const double interest_rate = 1.02;
  std::shared_ptr<qfm::FinanceApi> yahoo_finance_api =
      std::make_shared<qfm::YahooFinanceApi>();
  auto market_data_provider = std::make_shared<qfm::MarketDataProvider>(
      yahoo_finance_api, interest_rate);

  auto amzn_asset_quote =
      market_data_provider->GetAssetQuote(qfm::asset::AssetTicker("AMZN"));
  std::cout << "Output asset quote of AMZN" << std::endl;
  std::cout << "bid: " << amzn_asset_quote.bid
            << " and ask: " << amzn_asset_quote.ask << std::endl;

  auto model =
      std::make_shared<qfm::pricing::model::BlackScholes>(market_data_provider);

  qfm::pricing::Pricing pricing;
  pricing.SetModel(model, asset_type);

  return 0;
}
