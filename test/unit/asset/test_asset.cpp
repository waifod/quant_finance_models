/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 David Alvarez Rosa, Matteo Durante
 */

#include <gtest/gtest.h>

#include <qfm/asset/asset.hpp>
#include <qfm/asset/asset_trait_set.hpp>
#include <qfm/asset/asset_type.hpp>

TEST(TestAsset, GetTicker) {
  auto fake_ticker = qfm::asset::AssetTicker("fake_ticker");
  auto fake_type = qfm::asset::AssetType::stock;
  auto fake_traits =
      qfm::asset::AssetTraitSet(std::set<qfm::asset::AssetTrait>());
  auto asset = qfm::asset::Asset(fake_ticker, fake_type, fake_traits);
  EXPECT_EQ(asset.GetTicker(), fake_ticker);
}
