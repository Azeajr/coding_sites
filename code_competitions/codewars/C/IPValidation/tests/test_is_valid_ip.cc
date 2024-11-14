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
std::ostream &operator<<(std::ostream &os, const IsValidIpTestParam &param) {
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
  params.push_back(IsValidIpTestParam{is_valid_ip_v4, "is_valid_ip_v4"});
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