#include "qfm/asset/asset_type.hpp"

namespace qfm {
namespace asset {

namespace {
const std::string kCurrency = "currency";
const std::string kBond = "bond";
const std::string kStock = "stock";
const std::string kCallOption = "call_option";
const std::string kPutOption = "put_option";
const std::string kFuture = "future";
}  // namespace

std::string ToString(const AssetType& type) {
  switch (type) {
    case CURRENCY:
      return kCurrency;
    case BOND:
      return kBond;
    case STOCK:
      return kStock;
    case CALL_OPTION:
      return kCallOption;
    case PUT_OPTION:
      return kPutOption;
    case FUTURE:
      return kFuture;
  }
}

}  // namespace asset
}  // namespace qfm
