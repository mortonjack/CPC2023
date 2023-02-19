#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

double radius(double n, double r) {
    // Radius R + r = inner length of triangles in polygon
    // R is also base length of triangle
    // We are looking for R such that R + r = radius && R = side/2
    // Radius of inner circle is 2pi
    // n sections makes 2pi/n
    // Only look at half section (right-angled triangle) so theta = pi/n
    // opposite = R (side length/2)
    // hypoteneuse = R + r
    // sin(pi/n) = R/(R+r)
    // (R+r)sin(pi/n) = R
    // R sin(pi/n) + r sin(pi/n) = R
    // R - R sin(pi/n) = r sin(pi/n)
    // R(1 - sin(pi/n)) = r sin(pi/n)
    // R = r sin(pi/n) / (1 - sin(pi/n))
    double pi = 3.1415926535;
    double theta = pi/n;
    double sin_t = sin(theta);
    return (r*sin_t)/(1-sin_t);
}

int main() {
    double n, r;
    cin >> n >> r;

    cout << setprecision(7) << fixed << radius(n, r) << '\n';

    return 0;
}
