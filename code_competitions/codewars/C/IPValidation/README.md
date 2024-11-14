## Building
To build the project, follow these steps:
1. **Install Dependencies**:
    - [CMake](https://cmake.org/download/)
    - [Ninja](https://ninja-build.org/)

2. **Build the Project**:
```bash
cmake -S . -B build -G Ninja
ninja -C build
```

## Testing
To run the tests, follow these steps:
1. **Build the Project**:
```bash
cmake -S . -B build -G Ninja
ninja -C build
```

2. **Run the Tests**:
```bash
ctest -C build
```

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