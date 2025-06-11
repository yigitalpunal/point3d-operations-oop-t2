#include <iostream>
using namespace std;

class Point3D {
private:
    int x, y, z;

public:
    // Default constructor
    Point3D() {
        x = 0;
        y = 0;
        z = 0;
    }

    // Initializing constructor
    Point3D(int xVal, int yVal, int zVal) {
        x = xVal;
        y = yVal;
        z = zVal;
    }

    // Set functions
    void setX(int val) { x = val; }
    void setY(int val) { y = val; }
    void setZ(int val) { z = val; }

    // Get functions
    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }

    // Friend function to input point
    friend istream& operator>>(istream& in, Point3D& p);

    // Friend function to output point
    friend ostream& operator<<(ostream& out, const Point3D& p);

    // Friend function to add two points
    friend Point3D operator+(const Point3D& p1, const Point3D& p2);

    // Overloaded += operator
    Point3D& operator+=(int value) {
        x += value;
        y += value;
        z += value;
        return *this;
    }
};

// Input operator >>
istream& operator>>(istream& in, Point3D& p) {
    cout << "Enter x: ";
    in >> p.x;
    cout << "Enter y: ";
    in >> p.y;
    cout << "Enter z: ";
    in >> p.z;
    return in;
}

// Output operator <<
ostream& operator<<(ostream& out, const Point3D& p) {
    out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return out;
}

// Add two points
Point3D operator+(const Point3D& p1, const Point3D& p2) {
    return Point3D(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}

// Main function
int main() {
    Point3D point1, point2(1, 2, 3);

    cout << "Enter coordinates for point1:\n";
    cin >> point1;

    cout << "\nPoint 1: " << point1 << endl;
    cout << "Point 2: " << point2 << endl;

    Point3D sum = point1 + point2;
    cout << "point1 + point2 = " << sum << endl;

    point1 += 4;
    cout << "After point1 += 4: " << point1 << endl;

    return 0;
}
