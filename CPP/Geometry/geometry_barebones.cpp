struct Point {
    int x, y;

    bool operator== (Point const &o) const {
        return x == o.x && y == o.y;
    }

    bool operator< (Point const &o) const {
        if (x == o.x)
            return y < o.y;
        return x < o.x;
    }
};

struct Vec {
    int x, y;

    Vec(Point &a) {
        x = a.x;
        y = a.y;
    }

    Vec(Point &a, Point &b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    int dot(Vec const &o) {
        return x*o.x + y*o.y;
    }

    int cross(Vec const &o) {
        return y*o.x - x*o.y;
    }
};

bool perpendicular(Vec &a, Vec &b) {
    return a.dot(b) == 0;
}

bool parallel(Vec &a, Vec &b) {
    return a.cross(b) == 0;
}
