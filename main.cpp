#include <curl/curl.h>

#include <boost/math/distributions/normal.hpp>
#include <iostream>

#include "qfm/asset/asset_expiration.hpp"
#include "qfm/asset/asset_strike_price.hpp"
#include "qfm/asset/asset_trait_set.hpp"
#include "qfm/asset/asset_type.hpp"
#include "qfm/asset/option.hpp"
#include "qfm/asset/trait/expiration_trait.hpp"
#include "qfm/asset/trait/strike_price_trait.hpp"
#include "qfm/market_data_provider.hpp"
#include "qfm/pricing/model/black_scholes.hpp"
#include "qfm/pricing/pricing.hpp"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

int main() {
  std::cout << "Hello World!" << std::endl;

  std::cout << "Testing cURL library" << std::endl;
  // Example from https://curl.se/libcurl/c/curl_easy_init.html
  // modified as in https://gist.github.com/alghanmi/c5d7b761b2c9ab199157
  CURL *curl = curl_easy_init();
  if (curl) {
    CURLcode res;
    std::string readBuffer;
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.example.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    std::cout << readBuffer << std::endl;
  }

  std::cout << "Testing Boost math library" << std::endl;
  auto gaussian = boost::math::normal_distribution(0, 1);
  std::cout << "Outputting random value: " << cdf(gaussian, 2) << std::endl;

  std::string ticker{"fake_ticker"};
  qfm::asset::AssetType type{qfm::asset::AssetType::call_option};
  qfm::asset::AssetExpiration expiration{1704067200};
  qfm::asset::AssetStrikePrice strike_price{10};
  qfm::asset::AssetTraitSet traits{
      {qfm::asset::trait::ExpirationTrait(expiration),
       qfm::asset::trait::StrikePriceTrait(strike_price)}};
  auto asset = std::make_shared<qfm::asset::Asset>(ticker, type, traits);

  std::shared_ptr<qfm::MarketDataProvider> market_data_provider =
      std::make_shared<qfm::MarketDataProvider>();

  auto model =
      std::make_shared<qfm::pricing::model::BlackScholes>(market_data_provider);

  qfm::pricing::Pricing pricing;
  pricing.SetModel(model, type);

  std::cout << "Price of asset " << std::string(ticker)
            << " is: " << pricing.GetAssetPrice(asset) << std::endl;
}
