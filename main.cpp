#include <iostream>

#include <TestClass.hpp>

#include "market_data_provider.hpp"
#include "pricing/model/black_scholes.hpp"
#include "option.hpp"
#include "pricing/pricing.hpp"

#include <boost/math/distributions/normal.hpp>

using namespace std;

int main() {
  cout << "Hello world!" << endl;

  TestClass my_test_class;

  my_test_class.SayHello();

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
