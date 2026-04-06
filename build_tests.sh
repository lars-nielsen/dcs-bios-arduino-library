#!/bin/bash
# Build and run tests

set -e

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ../tests

# Build
cmake --build .

# Run tests
ctest --output-on-failure
