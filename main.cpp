#include <iostream>

#include <TestClass.hpp>

#include "market_data_provider.hpp"
#include "pricing/model/black_scholes.hpp"
#include "option.hpp"
#include "pricing/pricing.hpp"

using namespace std;

int main() {
  cout << "Hello world!" << endl;

  TestClass my_test_class;

  my_test_class.SayHello();

  Asset asset("hello");

  std::shared_ptr<MarketDataProvider> market_data_provider = std::make_shared<MarketDataProvider>();

  //auto model = Model(market_data_provider);
  auto model = BlackScholes(market_data_provider);

  //auto model = std::make_shared<BlackScholes>(market_data_provider);

  /*Pricing pricing;
  pricing.SetModel(model);

  std::cout << pricing.GetAssetPrice(asset) << std::endl;*/
}
