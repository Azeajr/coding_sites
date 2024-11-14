// benchmark/benchmark.c
#include <stdio.h>
#include <time.h>
#include "test_ips.h"
#include "../src/is_valid_ip.h" // Adjust the path if necessary

// Declare the two implementations from is_valid_ip.c
// Ensure that is_valid_ip_v1 and is_valid_ip_v2 are defined and exposed in is_valid_ip.h
extern int is_valid_ip_v1(const char *addr);
extern int is_valid_ip_v2(const char *addr);

// Function to get current time in nanoseconds
long long current_time_ns() {
    struct timespec ts;
    // Use CLOCK_MONOTONIC for measuring intervals
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000000LL + ts.tv_nsec;
}

// Benchmark function
void benchmark(int (*is_valid_ip_func)(const char *), const char *func_name, int iterations) {
    // Warm-up runs to stabilize CPU caches and branch predictors
    for (int i = 0; i < 1000; i++) {
        is_valid_ip_func(test_ips[i % NUM_TEST_IPS]);
    }

    long long start_ns = current_time_ns();
    int valid_count = 0;
    int invalid_count = 0;

    for (int i = 0; i < iterations; i++) {
        for (size_t j = 0; j < NUM_TEST_IPS; j++) {
            if (is_valid_ip_func(test_ips[j])) {
                valid_count++;
            } else {
                invalid_count++;
            }
        }
    }

    long long end_ns = current_time_ns();
    double total_time_sec = (end_ns - start_ns) / 1e9;

    printf("%s:\n", func_name);
    printf("  Total time: %.6f seconds\n", total_time_sec);
    printf("  Throughput: %.2f IPs/sec\n", (double)(NUM_TEST_IPS * iterations) / total_time_sec);
    printf("  Valid IPs: %d, Invalid IPs: %d\n\n", valid_count, invalid_count);
}

int main() {
    // Number of times to run the benchmark loop
    // Adjust based on desired total iterations and available time
    int iterations = 100000;

    printf("Starting Benchmarks...\n\n");

    // Run benchmark for Implementation 1
    benchmark(is_valid_ip_v1, "is_valid_ip_v1", iterations);

    // Run benchmark for Implementation 2
    benchmark(is_valid_ip_v2, "is_valid_ip_v2", iterations);

    // Run benchmark for Implementation 3
    benchmark(is_valid_ip_v3, "is_valid_ip_v3", iterations);

    // Run benchmark for Implementation 4
    benchmark(is_valid_ip_v4, "is_valid_ip_v4", iterations);

    return 0;
}
