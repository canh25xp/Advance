#pragma once
struct Point {
    Point();
    Point(int x, int y);

    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;

    Point operator+(const Point &rhs) const;
    void operator+=(const Point &rhs);
    void operator+=(const int &rhs);
    void operator++();

    Point operator-(const Point &rhs) const;
    void operator-=(const Point &rhs);
    void operator-=(const int &rhs);
    void operator--();

    int x, y;
};
