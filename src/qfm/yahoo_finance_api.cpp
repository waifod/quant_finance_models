/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include "qfm/yahoo_finance_api.hpp"

#include <curl/curl.h>
#include <curl/easy.h>

#include <nlohmann/json.hpp>

#include "qfm/asset/asset_ticker.hpp"

using namespace std;

namespace qfm {

namespace {

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

}  // namespace

double YahooFinanceApi::QueryBidPrice(
    const asset::AssetTicker &asset_ticker) const noexcept {
  CURL *curl = curl_easy_init();
  std::string readBuffer;
  auto endpoint = "https://query1.finance.yahoo.com/v7/finance/options/" +
                  std::string(asset_ticker);
  curl_easy_setopt(curl, CURLOPT_URL, endpoint.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
  curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  auto response = nlohmann::json::parse(readBuffer);

  auto result_array =
      response["optionChain"]["result"];
  auto quote_object =
      result_array[0]["quote"];

  return quote_object["bid"];
}

double YahooFinanceApi::QueryAskPrice(
    const asset::AssetTicker &asset_ticker) const noexcept {
  CURL *curl = curl_easy_init();
  std::string readBuffer;
  auto endpoint = "https://query1.finance.yahoo.com/v7/finance/options/" +
                  std::string(asset_ticker);
  curl_easy_setopt(curl, CURLOPT_URL, endpoint.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
  curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  auto response = nlohmann::json::parse(readBuffer);

  auto result_array =
      response["optionChain"]["result"];
  auto quote_object =
      result_array[0]["quote"];

  return quote_object["bid"];
}

}  // namespace qfm
