#include "../src/is_valid_ip.h"
#include <gtest/gtest.h>

// Test suite for invalid IP addresses
class IsValidIpInvalidTest : public ::testing::Test {};

TEST_F(IsValidIpInvalidTest, LeadingDot) {
  EXPECT_FALSE(is_valid_ip(".1.45.227")) << "\".1.45.227\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, EmptyString) {
  EXPECT_FALSE(is_valid_ip("")) << "\"\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, NonNumericCharacters) {
  EXPECT_FALSE(is_valid_ip("abc.def.ghi.jkl"))
      << "\"abc.def.ghi.jkl\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, OctetValueOutOfRange) {
  EXPECT_FALSE(is_valid_ip("123.456.789.0"))
      << "\"123.456.789.0\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, TooFewOctets) {
  EXPECT_FALSE(is_valid_ip("12.34.56")) << "\"12.34.56\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, SpaceInOctet) {
  EXPECT_FALSE(is_valid_ip("12.34.56 .1"))
      << "\"12.34.56 .1\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, NegativeOctetValue) {
  EXPECT_FALSE(is_valid_ip("12.34.56.-1"))
      << "\"12.34.56.-1\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, LeadingZerosInOctets) {
  EXPECT_FALSE(is_valid_ip("123.045.067.089"))
      << "\"123.045.067.089\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, ThreeOctets) {
  EXPECT_FALSE(is_valid_ip("1.2.3")) << "\"1.2.3\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, FiveOctets) {
  EXPECT_FALSE(is_valid_ip("1.2.3.4.5")) << "\"1.2.3.4.5\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, LargeOctetValues) {
  EXPECT_FALSE(is_valid_ip("123.456.78.90"))
      << "\"123.456.78.90\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, LeadingSpace) {
  EXPECT_FALSE(is_valid_ip(" 1.2.3.4")) << "\" 1.2.3.4\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, TrailingDot) {
  EXPECT_FALSE(is_valid_ip("1.2.3.4.")) << "\"1.2.3.4.\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, ConsecutiveDots) {
  EXPECT_FALSE(is_valid_ip("1..2.3.4")) << "\"1..2.3.4\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, EmptyOctet) {
  EXPECT_FALSE(is_valid_ip("1.2..4")) << "\"1.2..4\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, OctetWithSpaces) {
  EXPECT_FALSE(is_valid_ip("1. 2.3.4")) << "\"1. 2.3.4\" IS NOT a valid IP";
}

TEST_F(IsValidIpInvalidTest, OctetWithLetters) {
  EXPECT_FALSE(is_valid_ip("1.2.3.a")) << "\"1.2.3.a\" IS NOT a valid IP";
}

// Test suite for valid IP addresses
class IsValidIpValidTest : public ::testing::Test {};

TEST_F(IsValidIpValidTest, ValidIp1) {
  EXPECT_TRUE(is_valid_ip("12.255.56.1")) << "\"12.255.56.1\" IS a valid IP";
}

TEST_F(IsValidIpValidTest, ValidIp2) {
  EXPECT_TRUE(is_valid_ip("1.2.3.4")) << "\"1.2.3.4\" IS a valid IP";
}

TEST_F(IsValidIpValidTest, ValidIp3) {
  EXPECT_TRUE(is_valid_ip("123.45.67.89")) << "\"123.45.67.89\" IS a valid IP";
}

TEST_F(IsValidIpValidTest, ValidIpWithZeroOctet) {
  EXPECT_TRUE(is_valid_ip("1.0.2.3")) << "\"1.0.2.3\" IS a valid IP";
}

TEST_F(IsValidIpValidTest, AllZeros) {
  EXPECT_TRUE(is_valid_ip("0.0.0.0")) << "\"0.0.0.0\" IS a valid IP";
}

TEST_F(IsValidIpValidTest, All255s) {
  EXPECT_TRUE(is_valid_ip("255.255.255.255"))
      << "\"255.255.255.255\" IS a valid IP";
}

TEST_F(IsValidIpValidTest, PrivateIp) {
  EXPECT_TRUE(is_valid_ip("192.168.1.1")) << "\"192.168.1.1\" IS a valid IP";
}

TEST_F(IsValidIpValidTest, LoopbackIp) {
  EXPECT_TRUE(is_valid_ip("127.0.0.1")) << "\"127.0.0.1\" IS a valid IP";
}
