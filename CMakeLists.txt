cmake_minimum_required(VERSION 3.14)
project(CompositePattern VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(composite main.cpp)
install(TARGETS composite RUNTIME DESTINATION bin)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable(test_composite tests/test_composite.cpp)
target_link_libraries(test_composite GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(test_composite)

set(CPACK_PACKAGE_NAME "composite-pattern")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Example of Composite design pattern")
set(CPACK_GENERATOR "DEB")
include(CPack)
