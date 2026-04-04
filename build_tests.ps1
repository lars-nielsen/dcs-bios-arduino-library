# Build and run tests on Windows

if (-not (Test-Path "build")) {
    New-Item -ItemType Directory -Name "build" | Out-Null
}

Set-Location build

# Configure with CMake (requires CMake to be installed)
cmake ..

# Build
cmake --build . --config Debug

# Run tests
ctest --output-on-failure -C Debug
