# DCS mock library
add_library(DcsMock
    DcsMock.cpp
)

target_include_directories(DcsMock PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/test/mocks
)

