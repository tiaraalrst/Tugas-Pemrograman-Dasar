
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double pi = 3.1416;

// a. Distance between two points (x1, y1) dan (x2, y2)
double distance(double x1, double y1, double x2, double y2) {
    return sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) );
}

// b. Radius: center (px, py) and point on a circle (tx, ty)
double radius(double px, double py, double tx, double ty) {
    return distance(px, py, tx, ty);
}

// c. Circumference
double circumference(double r) {
    return 2.0 * pi * r;
}

// d. Area
double area(double r) {
    return pi * r * r;
}

int main() {
    double px, py; // pusat
    double tx, ty; // titik pada lingkaran

    cout << "Center coordinate (x y): ";
    cin >> px >> py;

    cout << "Point coordinate (x y): ";
    cin >> tx >> ty;

    double r = radius(px, py, tx, ty);
    double d = 2.0 * r;
    double c = circumference(r);
    double a = area(r);

    cout << fixed << setprecision(4);
    cout << "Result:\n";
    cout << "Radius        : " << r << '\n';
    cout << "Diameter      : " << d << '\n';
    cout << "Circumference      : " << c << '\n';
    cout << "Area          : " << a << '\n';

    return 0;
}