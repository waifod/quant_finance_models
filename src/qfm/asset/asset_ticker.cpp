#include "qfm/asset/asset_ticker.hpp"

namespace qfm {
namespace asset {

AssetTicker::AssetTicker(const std::string& ticker) noexcept
    : ticker_{ticker} {}

bool AssetTicker::operator==(const AssetTicker& ticker) const {
  return ticker_ == ticker.ticker_;
}
bool AssetTicker::operator==(const std::string& ticker) const {
  return ticker_ == ticker;
}
bool AssetTicker::operator!=(const AssetTicker& ticker) const {
  return ticker_ != ticker.ticker_;
}
bool AssetTicker::operator!=(const std::string& ticker) const {
  return ticker_ != ticker;
}

AssetTicker::operator std::string() const { return ticker_; }

}  // namespace asset
}  // namespace qfm
