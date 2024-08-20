const double PI = 4 * atan(1.0);
double low = PI / 2;
double high = PI;
const double eps = 1e-6;

while (high-low > eps) {
    double third = (high - low) / 3;
    double mid1 = low + third;
    double mid2 = low + 2*third;

    double v1 = volume(mid1);
    double v2 = volume(mid2);

    if (v1 < v2) low = mid1;
    else if (v1 == v2) {
        low = mid1;
        high = mid2;
    }
    else high = mid2;
}
