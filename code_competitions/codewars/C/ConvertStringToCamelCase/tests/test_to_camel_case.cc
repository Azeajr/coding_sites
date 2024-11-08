#include "to_camel_case.h"
#include <gtest/gtest.h>

TEST(ToCamelCase, Test0) {
  char camel[100];
  to_camel_case("", camel);
  ASSERT_STREQ("", camel);
}

TEST(ToCamelCase, Test1) {
  char camel[100];
  to_camel_case("the_stealth_warrior", camel);
  ASSERT_STREQ("theStealthWarrior", camel);
}

TEST(ToCamelCase, Test2) {
  char camel[100];
  to_camel_case("The-Stealth-Warrior", camel);
  ASSERT_STREQ("TheStealthWarrior", camel);
}

TEST(ToCamelCase, Test3) {
  char camel[100];
  to_camel_case("A-B-C", camel);
  ASSERT_STREQ("ABC", camel);
}