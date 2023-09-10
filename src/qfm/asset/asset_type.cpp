#include "qfm/asset/asset_type.hpp"

namespace qfm {
namespace asset {

namespace {
const std::string kCurrency{"currency"};
const std::string kBond{"bond"};
const std::string kStock{"stock"};
const std::string kCallOption{"call_option"};
const std::string kPutOption{"put_option"};
const std::string kFuture{"future"};
}  // namespace

std::string ToString(const AssetType& type) {
  switch (type) {
    case AssetType::CURRENCY:
      return kCurrency;
    case AssetType::BOND:
      return kBond;
    case AssetType::STOCK:
      return kStock;
    case AssetType::CALL_OPTION:
      return kCallOption;
    case AssetType::PUT_OPTION:
      return kPutOption;
    case AssetType::FUTURE:
      return kFuture;
  }
}

}  // namespace asset
}  // namespace qfm
