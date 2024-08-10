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

int orientation(Point a, Point b, Point c) {
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}

bool ccw(Point a, Point b, Point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<Point>& a, bool include_collinear = false) {
    Point p0 = *min_element(a.begin(), a.end());

    sort(a.begin(), a.end(), [&p0](const Point& a, const Point& b) { // sort by polar order
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o > 0;
    });

    if (include_collinear) {
        int i = a.size()-1;
        while (i >= 0 && orientation(p0, a[i], a.back()) == 0) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<Point> st;
    for (int i = 0; i < a.size(); i++) {
        while (st.size() > 1 && !ccw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (!include_collinear && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
}
