#include "asset/trait/expiration_trait.hpp"

ExpirationTrait::ExpirationTrait(const AssetExpiration& expiration) noexcept
    : AssetTrait(ExpirationTrait::Key, expiration) {}

const std::string ExpirationTrait::Key = "expiration_date";