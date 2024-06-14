#include <iostream>
#include <cmath>
using namespace std;

class Line {
private:
    int x1, y1, x2, y2;
    double slope, intercept;

public:
    // Constructors
    Line() : x1(0), y1(0), x2(0), y2(0), slope(0), intercept(0) {}
    Line(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {
        calculateSlopeAndIntercept();
    }

    // Getters and setters
    void setPoints(int _x1, int _y1, int _x2, int _y2) {
        x1 = _x1; y1 = _y1; x2 = _x2; y2 = _y2;
        calculateSlopeAndIntercept();
    }
    int getX1() const { return x1; }
    int getY1() const { return y1; }
    int getX2() const { return x2; }
    int getY2() const { return y2; }
    double getSlope() const { return slope; }
    double getIntercept() const { return intercept; }

    // Function to calculate slope and intercept
    void calculateSlopeAndIntercept() {
        if (x2 - x1 != 0) {
            slope = static_cast<double>(y2 - y1) / (x2 - x1);
            intercept = y1 - slope * x1;
        } else {
            slope = NAN;
            intercept = NAN;
        }
    }
};

class Circle {
private:
    int centerX, centerY, radius;
    double circumference, area;

public:
    // Constructors
    Circle() : centerX(0), centerY(0), radius(0), circumference(0), area(0) {}
    Circle(int cx, int cy) : centerX(cx), centerY(cy), radius(0) {
        calculateProperties();
    }
    Circle(int cx, int cy, int r) : centerX(cx), centerY(cy), radius(r) {
        calculateProperties();
    }

    // Getters and setters
    void setCenter(int cx, int cy) {
        centerX = cx;
        centerY = cy;
        calculateProperties();
    }
    void setRadius(int r) {
        radius = r;
        calculateProperties();
    }
    int getCenterX() const { return centerX; }
    int getCenterY() const { return centerY; }
    int getRadius() const { return radius; }
    double getArea() const { return area; }
    double getCircumference() const { return circumference; }

    // Calculate area and circumference
    void calculateProperties() {
        area = M_PI * radius * radius;
        circumference = 2 * M_PI * radius;
    }

    // Overloaded functions to check if a line is tangent
    bool isTangent(int x1, int y1, int x2, int y2) {
        Line l(x1, y1, x2, y2);
        return isTangent(l);
    }

    bool isTangent(int slope, int intercept) {
        Line l(0, intercept, 1, slope + intercept);
        return isTangent(l);
    }

    bool isTangent(Line l) {
        double d = abs(l.getSlope() * centerX - centerY + l.getIntercept()) / sqrt(l.getSlope() * l.getSlope() + 1);
        return (d == radius);
    }

    // Simple draw function
    void draw() {
        cout << "Drawing circle with center (" << centerX << ", " << centerY << ") and radius " << radius << endl;
    }
};

int main() {
    Circle c(0, 0, 5);
    c.draw();

    cout << "Area: " << c.getArea() << endl;
    cout << "Circumference: " << c.getCircumference() << endl;

    // Example usage of tangent checking
    Line l1(0, 0, 5, 5);
    Line l2(0, 1, 1, 0);
    cout << "Is line l1 tangent to the circle? " << (c.isTangent(l1) ? "Yes" : "No") << endl;
    cout << "Is line l2 tangent to the circle? " << (c.isTangent(l2) ? "Yes" : "No") << endl;

    return 0;
}
