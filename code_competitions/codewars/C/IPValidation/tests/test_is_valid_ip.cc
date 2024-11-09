#include "../src/is_valid_ip.h"
#include <gtest/gtest.h>

TEST(IsValidIp, Test0) {
  EXPECT_EQ(false, is_valid_ip(".1.45.227"))
      << "\".1.45.227\" IS NOT a valid IP";
  EXPECT_EQ(true, is_valid_ip("12.255.56.1"))
      << "\"12.255.56.1\" IS a valid IP";
  EXPECT_EQ(false, is_valid_ip("")) << "\"\" IS NOT a valid IP";
  EXPECT_EQ(false, is_valid_ip("abc.def.ghi.jkl"))
      << "\"abc.def.ghi.jkl\" IS NOT a valid IP";
  EXPECT_EQ(false, is_valid_ip("123.456.789.0"))
      << "\"123.456.789.0\" IS NOT a valid IP";
  EXPECT_EQ(false, is_valid_ip("12.34.56")) << "\"12.34.56\" IS NOT a valid IP";
  EXPECT_EQ(false, is_valid_ip("12.34.56 .1"))
      << "\"12.34.56 .1\" IS NOT a valid IP";
  EXPECT_EQ(false, is_valid_ip("12.34.56.-1"))
      << "\"12.34.56.-1\" IS NOT a valid IP";
  EXPECT_EQ(false, is_valid_ip("123.045.067.089"))
      << "\"123.045.067.089\" IS NOT a valid IP";
  EXPECT_EQ(true, is_valid_ip("1.2.3.4")) << "\"1.2.3.4\" IS a valid IP";
  EXPECT_EQ(true, is_valid_ip("123.45.67.89"))
      << "\"123.45.67.89\" IS a valid IP";
  EXPECT_EQ(false, is_valid_ip("1.2.3")) << "\"1.2.3\" IS NOT a valid IP";
  EXPECT_EQ(false, is_valid_ip("1.2.3.4.5"))
      << "\"1.2.3.4.5\" IS NOT a valid IP";
  EXPECT_EQ(false, is_valid_ip("123.456.78.90"))
      << "\"123.456.78.90\" IS NOT a valid IP";
}
