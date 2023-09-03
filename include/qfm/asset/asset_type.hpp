#pragma once

#include <string>

namespace qfm {
namespace asset {

enum AssetType { CURRENCY, BOND, STOCK, CALL_OPTION, PUT_OPTION, FUTURE };

std::string ToString(const AssetType& type);

}  // namespace asset
}  // namespace qfm
