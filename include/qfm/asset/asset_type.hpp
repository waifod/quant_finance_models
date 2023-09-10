#pragma once

#include <string>

namespace qfm {
namespace asset {

enum class AssetType { currency, bond, stock, call_option, put_option, future };

std::string ToString(const AssetType& type);

}  // namespace asset
}  // namespace qfm
