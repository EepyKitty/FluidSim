#include "vec2.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_all.hpp>
#include <catch2/generators/catch_generators_random.hpp>

TEST_CASE("Vec2 equals") {
    auto x1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y1 = GENERATE(take(10, random(-100.0, 100.0)));
    Vec2 a{x1, y1};
    REQUIRE(a == a);
}

TEST_CASE("Vec2 addition") {
    auto x1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto x2 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y2 = GENERATE(take(10, random(-100.0, 100.0)));
    Vec2 a{x1, y1}, b{x2, y2};
    REQUIRE(a + b == Vec2{x1 + x2, y1 + y2});
}

TEST_CASE("dot is commutative") {
    auto x1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto x2 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y2 = GENERATE(take(10, random(-100.0, 100.0)));
    Vec2 a{x1, y1}, b{x2, y2};
    REQUIRE(dot(a, b) == dot(b, a));
}
