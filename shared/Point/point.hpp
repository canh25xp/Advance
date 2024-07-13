struct Point {
    int r, c;

    Point() : r(0), c(0) {}

    Point(int r, int c) : r(r), c(c) {}

    bool operator==(const Point &rhs) const {
        if (r == rhs.r && c == rhs.c)
            return true;
        return false;
    }

    bool operator!=(const Point &rhs) const {
        if (r == rhs.r && c == rhs.c)
            return false;
        return true;
    }

    Point operator+(const Point &rhs) const {
        return Point(r + rhs.r, c + rhs.c);
    }

    void operator+=(const Point &rhs) {
        r += rhs.r;
        c += rhs.c;
    }

    void operator+=(const int &rhs) {
        r += rhs;
        c += rhs;
    }

    void operator++() {
        r++;
        c++;
    }

    Point operator-(const Point &rhs) const {
        return Point(r - rhs.r, c - rhs.c);
    }

    void operator-=(const Point &rhs) {
        r -= rhs.r;
        c -= rhs.c;
    }

    void operator-=(const int &rhs) {
        r -= rhs;
        c -= rhs;
    }

    void operator--() {
        r--;
        c--;
    }
};
