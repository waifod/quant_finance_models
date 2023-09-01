#include "qfm/asset/trait/type_trait.hpp"

#include <string>

#include "qfm/asset/asset_type.hpp"

TypeTrait::TypeTrait(const AssetType& type) noexcept
    : AssetTrait(TypeTrait::Key, type) {}

const std::string TypeTrait::Key = "type";
