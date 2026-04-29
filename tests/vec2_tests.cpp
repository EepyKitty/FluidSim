#include "vec2.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_all.hpp>
#include <catch2/generators/catch_generators_random.hpp>
#include <cmath>

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

TEST_CASE("Vec2 subtraction") {
    auto x1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto x2 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y2 = GENERATE(take(10, random(-100.0, 100.0)));
    Vec2 a{x1, y1}, b{x2, y2};
    REQUIRE(a - b == Vec2{x1 - x2, y1 - y2});
}

TEST_CASE("Vec2 negation") {
    auto x = GENERATE(take(20, random(-100.0, 100.0)));
    auto y = GENERATE(take(20, random(-100.0, 100.0)));
    Vec2 v{x, y};
    REQUIRE(-v == Vec2{-x, -y});
}

TEST_CASE("Vec2 scalar multiplication") {
    auto x = GENERATE(take(10, random(-100.0, 100.0)));
    auto y = GENERATE(take(10, random(-100.0, 100.0)));
    auto k = GENERATE(take(10, random(-100.0, 100.0)));
    Vec2 v{x, y};
    REQUIRE(v * k == Vec2{x * k, y * k});
    REQUIRE(k * v == v * k);
}

TEST_CASE("Vec2 scalar division") {
    auto x = GENERATE(take(10, random(-100.0, 100.0)));
    auto y = GENERATE(take(10, random(-100.0, 100.0)));
    auto k = GENERATE(take(10, filter([](double v){ return std::abs(v) > 1e-9; }, random(-100.0, 100.0))));
    Vec2 v{x, y};
    REQUIRE(v / k == Vec2{x / k, y / k});
}

TEST_CASE("Vec2 += ") {
    auto x1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto x2 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y2 = GENERATE(take(10, random(-100.0, 100.0)));
    Vec2 a{x1, y1};
    a += Vec2{x2, y2};
    REQUIRE(a == Vec2{x1 + x2, y1 + y2});
}

TEST_CASE("Vec2 -=") {
    auto x1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto x2 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y2 = GENERATE(take(10, random(-100.0, 100.0)));
    Vec2 a{x1, y1};
    a -= Vec2{x2, y2};
    REQUIRE(a == Vec2{x1 - x2, y1 - y2});
}

TEST_CASE("Vec2 *=") {
    auto x = GENERATE(take(10, random(-100.0, 100.0)));
    auto y = GENERATE(take(10, random(-100.0, 100.0)));
    auto k = GENERATE(take(10, random(-100.0, 100.0)));
    Vec2 v{x, y};
    v *= k;
    REQUIRE(v == Vec2{x * k, y * k});
}

TEST_CASE("Vec2 /=") {
    auto x = GENERATE(take(10, random(-100.0, 100.0)));
    auto y = GENERATE(take(10, random(-100.0, 100.0)));
    auto k = GENERATE(take(10, filter([](double v){ return std::abs(v) > 1e-9; }, random(-100.0, 100.0))));
    Vec2 v{x, y};
    v /= k;
    REQUIRE(v == Vec2{x / k, y / k});
}

TEST_CASE("Vec2 length_squared") {
    auto x = GENERATE(take(20, random(-100.0, 100.0)));
    auto y = GENERATE(take(20, random(-100.0, 100.0)));
    REQUIRE(Vec2{x, y}.length_squared() == x*x + y*y);
}

TEST_CASE("Vec2 length") {
    auto x = GENERATE(take(20, random(-100.0, 100.0)));
    auto y = GENERATE(take(20, random(-100.0, 100.0)));
    REQUIRE(Vec2{x, y}.length() == Catch::Approx(std::sqrt(x*x + y*y)));
}

TEST_CASE("dot is commutative") {
    auto x1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y1 = GENERATE(take(10, random(-100.0, 100.0)));
    auto x2 = GENERATE(take(10, random(-100.0, 100.0)));
    auto y2 = GENERATE(take(10, random(-100.0, 100.0)));
    Vec2 a{x1, y1}, b{x2, y2};
    REQUIRE(dot(a, b) == dot(b, a));
}

TEST_CASE("dot with self is length_squared") {
    auto x = GENERATE(take(20, random(-100.0, 100.0)));
    auto y = GENERATE(take(20, random(-100.0, 100.0)));
    Vec2 v{x, y};
    REQUIRE(dot(v, v) == v.length_squared());
}
