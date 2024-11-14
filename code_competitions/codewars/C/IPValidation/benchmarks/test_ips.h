// benchmark/test_ips.h
#ifndef TEST_IPS_H
#define TEST_IPS_H

static const char *test_ips[] = {
    "192.168.1.1",
    "255.255.255.255",
    "0.0.0.0",
    "127.0.0.1",
    "1.1.1.1",
    "256.100.50.25",      // Invalid
    "192.168.1",          // Invalid
    "192.168.1.1.1",      // Invalid
    "192.168.01.1",       // Invalid (leading zero)
    "abc.def.gha.bcd",    // Invalid
    "123.045.067.089",    // Invalid (leading zeros)
    "1.2.3.4",
    "1.0.2.3",
    "127.0.0.1",
    // Add more as needed
};

#define NUM_TEST_IPS (sizeof(test_ips) / sizeof(test_ips[0]))

#endif // TEST_IPS_H
