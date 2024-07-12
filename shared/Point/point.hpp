struct Point {
    int x, y;

    Point() : x(0), y(0) {}

    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point &rhs) const {
        if (this->x == rhs.x && this->y == rhs.y)
            return true;
        return false;
    }

    bool operator!=(const Point &rhs) const {
        if (this->x == rhs.x && this->y == rhs.y)
            return false;
        return true;
    }

    Point operator+(const Point &rhs) const {
        return Point(this->x + rhs.x, this->y + rhs.y);
    }

    void operator+=(const Point &rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
    }

    void operator+=(const int &rhs) {
        this->x += rhs;
        this->y += rhs;
    }

    void operator++() {
        this->x++;
        this->y++;
    }

    Point operator-(const Point &rhs) const {
        return Point(this->x - rhs.x, this->y - rhs.y);
    }

    void operator-=(const Point &rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
    }

    void operator-=(const int &rhs) {
        this->x -= rhs;
        this->y -= rhs;
    }

    void operator--() {
        this->x--;
        this->y--;
    }
};
