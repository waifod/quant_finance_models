#include "qfm/asset/trait/type_trait.hpp"

#include <string>

#include "qfm/asset/asset_type.hpp"

namespace qfm {
namespace asset {
namespace trait {

TypeTrait::TypeTrait(const AssetType& type) noexcept
    : AssetTrait(TypeTrait::Key, type) {}

const std::string TypeTrait::Key = "type";

}  // namespace trait
}  // namespace asset
}  // namespace qfm
