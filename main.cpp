#include <iostream>

#include <boost/math/distributions/normal.hpp>

#include "asset/option.hpp"
#include "market_data_provider.hpp"
#include "pricing/model/black_scholes.hpp"
#include "pricing/pricing.hpp"

int main() {
  std::cout << "Hello World!" << std::endl;

  auto gaussian = boost::math::normal_distribution(0, 1);
  std::cout << "Outputting random value: " << cdf(gaussian, 2) << std::endl;

  std::string ticker{"fake_ticker"};
  auto asset = std::make_shared<Asset>(ticker);

  std::shared_ptr<MarketDataProvider> market_data_provider = std::make_shared<MarketDataProvider>();

  auto model = std::make_shared<BlackScholes>(market_data_provider);

  Pricing pricing;
  pricing.SetModel(model);

  std::cout << "Price of asset " << ticker << " is: " << pricing.GetAssetPrice(asset) << std::endl;
}
