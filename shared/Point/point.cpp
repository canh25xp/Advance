#include "point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

bool Point::operator==(const Point &rhs) const {
    if (this->x == rhs.x && this->y == rhs.y)
        return true;
    return false;
}

bool Point::operator!=(const Point &rhs) const {
    if (this->x == rhs.x && this->y == rhs.y)
        return false;
    return true;
}

void Point::operator+=(const Point &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
}

void Point::operator+=(const int &rhs) {
    this->x += rhs;
    this->y += rhs;
}

void Point::operator++() {
    this->x++;
    this->y++;
}

void Point::operator-=(const Point &rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
}

void Point::operator-=(const int &rhs) {
    this->x -= rhs;
    this->y -= rhs;
}

Point Point::operator+(const Point &rhs) const {
    return Point(this->x + rhs.x, this->y + rhs.y);
}

Point Point::operator-(const Point &rhs) const {
    return Point(this->x - rhs.x, this->y - rhs.y);
}

void Point::operator--() {
    this->x--;
    this->y--;
}