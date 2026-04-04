# Fetch Google Test from GitHub
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
FetchContent_MakeAvailable(googletest)

# DCS mock library (separate target)
add_subdirectory(mocks/dcs)

# Arduino mock library (subdir)
add_subdirectory(mocks/arduino)

# Add unit tests
add_subdirectory(unit)
