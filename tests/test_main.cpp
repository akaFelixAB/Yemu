// test_main.cpp
// Example unit test using Catch2 (if enabled)
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

TEST_CASE("Basic test", "[core]")
{
    REQUIRE(1 + 1 == 2);
}
