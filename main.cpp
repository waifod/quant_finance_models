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

int main() {
  std::cout << "Hello World!" << std::endl;

  auto gaussian = boost::math::normal_distribution(0, 1);
  std::cout << "Outputting random value: " << cdf(gaussian, 2) << std::endl;

  std::string ticker{"fake_ticker"};
  qfm::asset::AssetType type{qfm::asset::AssetType::CALL_OPTION};
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
