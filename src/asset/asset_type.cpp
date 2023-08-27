#include "asset/asset_type.hpp"

AssetType::AssetType(const std::string& type) noexcept : type_{type} {}

bool AssetType::operator==(const AssetType& type) const {
  return type_ == type.type_;
}
bool AssetType::operator==(const std::string& type) const {
  return type_ == type;
}
bool AssetType::operator!=(const AssetType& type) const {
  return type_ != type.type_;
}
bool AssetType::operator!=(const std::string& type) const {
  return type_ != type;
}

AssetType::operator std::string() const { return type_; }

const AssetType AssetType::CURRENCY = AssetType("currency");
const AssetType AssetType::CALL_OPTION = AssetType("call_option");
const AssetType AssetType::PUT_OPTION = AssetType("currency");
const AssetType AssetType::FUTURE = AssetType("currency");
const AssetType AssetType::STOCK = AssetType("stock");