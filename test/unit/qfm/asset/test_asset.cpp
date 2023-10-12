#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_trait_set.hpp"
#include "qfm/asset/asset_type.hpp"

using namespace qfm::asset;

TEST(TestAsset, GetTicker) {
  auto fake_ticker = AssetTicker("fake_ticker");
  auto fake_type = AssetType::stock;
  auto fake_traits = AssetTraitSet(std::set<AssetTrait>());
  auto asset = Asset(fake_ticker, fake_type, fake_traits);
  EXPECT_EQ(asset.GetTicker(), fake_ticker);
}