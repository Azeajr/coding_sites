#include <gtest/gtest.h>
#include "beeramid.hpp"

TEST(BeeramidTest, BeeramidCheck){
  EXPECT_EQ(12, beeramid(1500, 2));
}