#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y, z;
};

// Function to scale a point by given factors along each axis
void scale(Point& p, double scaleX, double scaleY, double scaleZ) {
    p.x *= scaleX;
    p.y *= scaleY;
    p.z *= scaleZ;
}

int main() {
    // Initial coordinates of the cube's vertices
    vector<Point> vertices = {{-1, -1, -1}, {-1, -1, 1}, {-1, 1, -1}, {-1, 1, 1},
                               {1, -1, -1}, {1, -1, 1}, {1, 1, -1}, {1, 1, 1}};

    // Scaling factors
    double scaleX = 1.5;
    double scaleY = 0.8;
    double scaleZ = 1.2;

    // Apply scaling to each vertex of the cube
    for (auto& vertex : vertices) {
        scale(vertex, scaleX, scaleY, scaleZ);
    }

    // Print scaled coordinates of the cube's vertices
    cout << "Scaled Cube Vertices:" << endl;
    for (const auto& vertex : vertices) {
        cout << "(" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")" << endl;
    }

    return 0;
}
