#pragma once

#include <cmath>

struct Vec2 {
  double x;
  double y;

  constexpr double length_squared() const {
    return x*x + y*y;
  }
  double length() const {
    return std::sqrt(length_squared());
  }
  constexpr Vec2 operator-() const {
    return Vec2{-x, -y};
  }
  constexpr Vec2& operator+=(const Vec2& v) {
    x += v.x;
    y += v.y;
    return *this;
  }
  constexpr Vec2& operator-=(const Vec2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }
  constexpr Vec2& operator*=(double k) {
    x *= k;
    y *= k;
    return *this;
  }
  constexpr Vec2& operator/=(double k) {
    x /= k;
    y /= k;
    return *this;
  }
  constexpr bool operator==(const Vec2&) const = default;
};

constexpr Vec2 operator+(Vec2 v1, const Vec2& v2) {
  return v1 += v2;
}
constexpr Vec2 operator-(Vec2 v1, const Vec2& v2) {
  return v1 -= v2;
}
constexpr Vec2 operator*(Vec2 v, double k) {
  return v *= k;
}
constexpr Vec2 operator*(double k, const Vec2& v) {
  return v * k;
}
constexpr Vec2 operator/(Vec2 v, double k) {
  return v /= k;
}
constexpr double dot(const Vec2& v1, const Vec2& v2) {
  return v1.x*v2.x + v1.y*v2.y;
}
