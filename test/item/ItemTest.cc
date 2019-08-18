#include "item/Item.h"
#include <gtest/gtest.h>

using namespace Pathos;

const std::string kItemName = "Item";
const size_t kSellPrice = 100;
const size_t kBuyPrice = 200;

TEST(ItemTest, ConstructorParametersCorrect) {
  Item item = Item(kItemName, kSellPrice, kBuyPrice);

  EXPECT_EQ(item.getName(), kItemName);
  EXPECT_EQ(item.getSellPrice(), kSellPrice);
  EXPECT_EQ(item.getBuyPrice(), kBuyPrice);
}

TEST(ItemTest, SetNameSellPriceBuyPrice) {
  Item item = Item(kItemName, kSellPrice, kBuyPrice);
  item.setName("NewItem");
  item.setSellPrice(400);
  item.setBuyPrice(500);

  EXPECT_EQ(item.getName(), "NewItem");
  EXPECT_EQ(item.getSellPrice(), 400);
  EXPECT_EQ(item.getBuyPrice(), 500);
}
