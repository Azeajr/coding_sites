#include "../src/is_valid_ip.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

typedef int (*is_valid_ip_fn)(const char *);

struct IsValidIpTestParam {
  is_valid_ip_fn func;
  std::string name;
};

// Overload operator<< for IsValidIpTestParam to customize print behavior
std::ostream& operator<<(std::ostream& os, const IsValidIpTestParam& param) {
    return os << param.name;
}

class IsValidIpParameterizedTest
    : public ::testing::TestWithParam<IsValidIpTestParam> {};

// Macro to define tests with current parameter's function
#define DEFINE_IP_TEST(test_name, input, expected)                             \
  TEST_P(IsValidIpParameterizedTest, test_name) {                              \
    EXPECT_EQ(GetParam().func(input), expected) << "\"" << input << "\"";      \
  }

// Instantiate the test parameters
std::vector<IsValidIpTestParam> getTestParams() {
  std::vector<IsValidIpTestParam> params;
  params.push_back(IsValidIpTestParam{is_valid_ip_v1, "is_valid_ip_v1"});
  params.push_back(IsValidIpTestParam{is_valid_ip_v2, "is_valid_ip_v2"});
  params.push_back(IsValidIpTestParam{is_valid_ip_v3, "is_valid_ip_v3"});
  // Add more implementations here if available
  return params;
}

// Define the name generator lambda
auto name_generator =
    [](const ::testing::TestParamInfo<IsValidIpTestParam> &info) {
      return info.param.name;
    };

// Register the test suite with the parameters and name generator
INSTANTIATE_TEST_SUITE_P(AllImplementations, IsValidIpParameterizedTest,
                         ::testing::ValuesIn(getTestParams()), name_generator);

// Test suite for invalid IP addresses
DEFINE_IP_TEST(LeadingDot, ".1.45.227", 0)
DEFINE_IP_TEST(EmptyString, "", 0)
DEFINE_IP_TEST(NonNumericCharacters, "abc.def.ghi.jkl", 0)
DEFINE_IP_TEST(OctetValueOutOfRange, "123.456.789.0", 0)
DEFINE_IP_TEST(TooFewOctets, "12.34.56", 0)
DEFINE_IP_TEST(SpaceInOctet, "12.34.56 .1", 0)
DEFINE_IP_TEST(NegativeOctetValue, "12.34.56.-1", 0)
DEFINE_IP_TEST(LeadingZerosInOctets, "123.045.067.089", 0)
DEFINE_IP_TEST(ThreeOctets, "1.2.3", 0)
DEFINE_IP_TEST(FiveOctets, "1.2.3.4.5", 0)
DEFINE_IP_TEST(LargeOctetValues, "123.456.78.90", 0)
DEFINE_IP_TEST(LeadingSpace, " 1.2.3.4", 0)
DEFINE_IP_TEST(TrailingDot, "1.2.3.4.", 0)
DEFINE_IP_TEST(ConsecutiveDots, "1..2.3.4", 0)
DEFINE_IP_TEST(EmptyOctet, "1.2..4", 0)
DEFINE_IP_TEST(OctetWithSpaces, "1. 2.3.4", 0)
DEFINE_IP_TEST(OctetWithLetters, "1.2.3.a", 0)

// Test suite for valid IP addresses
DEFINE_IP_TEST(ValidIp1, "12.255.56.1", 1)
DEFINE_IP_TEST(ValidIp2, "1.2.3.4", 1)
DEFINE_IP_TEST(ValidIp3, "123.45.67.89", 1)
DEFINE_IP_TEST(ValidIpWithZeroOctet, "1.0.2.3", 1)
DEFINE_IP_TEST(AllZeros, "0.0.0.0", 1)
DEFINE_IP_TEST(All255s, "255.255.255.255", 1)
DEFINE_IP_TEST(PrivateIp, "192.168.1.1", 1)
DEFINE_IP_TEST(LoopbackIp, "127.0.0.1", 1)

// // Test suite for invalid IP addresses
// class IsValidIpInvalidTest : public ::testing::Test {};

// TEST_F(IsValidIpInvalidTest, LeadingDot) {
//   EXPECT_FALSE(is_valid_ip_v1(".1.45.227"))
//       << "\".1.45.227\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, EmptyString) {
//   EXPECT_FALSE(is_valid_ip_v1("")) << "\"\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, NonNumericCharacters) {
//   EXPECT_FALSE(is_valid_ip_v1("abc.def.ghi.jkl"))
//       << "\"abc.def.ghi.jkl\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, OctetValueOutOfRange) {
//   EXPECT_FALSE(is_valid_ip_v1("123.456.789.0"))
//       << "\"123.456.789.0\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, TooFewOctets) {
//   EXPECT_FALSE(is_valid_ip_v1("12.34.56")) << "\"12.34.56\" IS NOT a valid
//   IP";
// }

// TEST_F(IsValidIpInvalidTest, SpaceInOctet) {
//   EXPECT_FALSE(is_valid_ip_v1("12.34.56 .1"))
//       << "\"12.34.56 .1\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, NegativeOctetValue) {
//   EXPECT_FALSE(is_valid_ip_v1("12.34.56.-1"))
//       << "\"12.34.56.-1\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, LeadingZerosInOctets) {
//   EXPECT_FALSE(is_valid_ip_v1("123.045.067.089"))
//       << "\"123.045.067.089\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, ThreeOctets) {
//   EXPECT_FALSE(is_valid_ip_v1("1.2.3")) << "\"1.2.3\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, FiveOctets) {
//   EXPECT_FALSE(is_valid_ip_v1("1.2.3.4.5"))
//       << "\"1.2.3.4.5\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, LargeOctetValues) {
//   EXPECT_FALSE(is_valid_ip_v1("123.456.78.90"))
//       << "\"123.456.78.90\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, LeadingSpace) {
//   EXPECT_FALSE(is_valid_ip_v1(" 1.2.3.4")) << "\" 1.2.3.4\" IS NOT a valid
//   IP";
// }

// TEST_F(IsValidIpInvalidTest, TrailingDot) {
//   EXPECT_FALSE(is_valid_ip_v1("1.2.3.4.")) << "\"1.2.3.4.\" IS NOT a valid
//   IP";
// }

// TEST_F(IsValidIpInvalidTest, ConsecutiveDots) {
//   EXPECT_FALSE(is_valid_ip_v1("1..2.3.4")) << "\"1..2.3.4\" IS NOT a valid
//   IP";
// }

// TEST_F(IsValidIpInvalidTest, EmptyOctet) {
//   EXPECT_FALSE(is_valid_ip_v1("1.2..4")) << "\"1.2..4\" IS NOT a valid IP";
// }

// TEST_F(IsValidIpInvalidTest, OctetWithSpaces) {
//   EXPECT_FALSE(is_valid_ip_v1("1. 2.3.4")) << "\"1. 2.3.4\" IS NOT a valid
//   IP";
// }

// TEST_F(IsValidIpInvalidTest, OctetWithLetters) {
//   EXPECT_FALSE(is_valid_ip_v1("1.2.3.a")) << "\"1.2.3.a\" IS NOT a valid IP";
// }

// // Test suite for valid IP addresses
// class IsValidIpValidTest : public ::testing::Test {};

// TEST_F(IsValidIpValidTest, ValidIp1) {
//   EXPECT_TRUE(is_valid_ip_v1("12.255.56.1")) << "\"12.255.56.1\" IS a valid
//   IP";
// }

// TEST_F(IsValidIpValidTest, ValidIp2) {
//   EXPECT_TRUE(is_valid_ip_v1("1.2.3.4")) << "\"1.2.3.4\" IS a valid IP";
// }

// TEST_F(IsValidIpValidTest, ValidIp3) {
//   EXPECT_TRUE(is_valid_ip_v1("123.45.67.89"))
//       << "\"123.45.67.89\" IS a valid IP";
// }

// TEST_F(IsValidIpValidTest, ValidIpWithZeroOctet) {
//   EXPECT_TRUE(is_valid_ip_v1("1.0.2.3")) << "\"1.0.2.3\" IS a valid IP";
// }

// TEST_F(IsValidIpValidTest, AllZeros) {
//   EXPECT_TRUE(is_valid_ip_v1("0.0.0.0")) << "\"0.0.0.0\" IS a valid IP";
// }

// TEST_F(IsValidIpValidTest, All255s) {
//   EXPECT_TRUE(is_valid_ip_v1("255.255.255.255"))
//       << "\"255.255.255.255\" IS a valid IP";
// }

// TEST_F(IsValidIpValidTest, PrivateIp) {
//   EXPECT_TRUE(is_valid_ip_v1("192.168.1.1")) << "\"192.168.1.1\" IS a valid
//   IP";
// }

// TEST_F(IsValidIpValidTest, LoopbackIp) {
//   EXPECT_TRUE(is_valid_ip_v1("127.0.0.1")) << "\"127.0.0.1\" IS a valid IP";
// }
