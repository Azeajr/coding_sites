## Benchmarking

To benchmark the performance of different `is_valid_ip` implementations, follow these steps:
1. **Build the Project**:
```bash
cmake -S . -B build -G Ninja
ninja -C build
```

2. **Run the Benchmark**:
```bash
./build/benchmark
```

3. **View the Results**:
    The benchmark will output the total time taken, throughput (IPs processed per second), and counts of valid and invalid IPs processed.