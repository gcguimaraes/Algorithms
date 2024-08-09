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

    Vec() {}
    Vec(Point &a) : x(a.x), y(a.y) {}
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

struct Line {
    int a, b, c; // coefficients of ax + by + c = 0;

    Line() {}
    Line(Point &p1, Point &p2) {
        if (p1.x == p2.x) { // vertical
            a = 1;
            b = 0;
            c = -p1.x;
        }
        else {
            a = -1.0 * (p1.y - p2.y) / (p1.x - p2.x);
            b = 1;
            c = -1.0 * (a * p1.x) - p1.y;
        }
    }

    bool operator== (Line const &o) {
        return a == o.a && b == o.b && c == o.c;
    }
};

bool parallel(Line &l1, Line &l2) {
    return l1.a == l2.a && l1.b == l2.b;
}

bool intersection(Line &l1, Line &l2, Point &out) {
    if (parallel(l1, l2)) return false;
    out.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (l1.b == 0) out.y = -(l2.a * out.x + l2.c); // vertical
    else out.y = -(l1.a * out.x + l1.c);
    return true;
}
