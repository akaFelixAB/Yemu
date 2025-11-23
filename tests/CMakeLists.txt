# CMake configuration for tests
cmake_minimum_required(VERSION 3.16)

# Only compile Catch2 when FEMU_ENABLE_TESTS option is enabled in the root CMakeLists.txt
include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(catch2)
add_executable(test_main test_main.cpp)
target_link_libraries(test_main PRIVATE Catch2::Catch2WithMain)
target_include_directories(test_main PRIVATE
    ${catch2_SOURCE_DIR}/src
    ${catch2_SOURCE_DIR}/src/catch2
)
add_test(NAME YemuTests COMMAND test_main)
