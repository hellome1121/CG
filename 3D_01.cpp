#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y, z;
};

// Function to translate a point by given offsets
void translate(Point& p, double offsetX, double offsetY, double offsetZ) {
    p.x += offsetX;
    p.y += offsetY;
    p.z += offsetZ;
}

int main() {
    // Initial coordinates of the cube's vertices
    vector<Point> vertices = {{-1, -1, -1}, {-1, -1, 1}, {-1, 1, -1}, {-1, 1, 1},
                               {1, -1, -1}, {1, -1, 1}, {1, 1, -1}, {1, 1, 1}};

    // Translation offsets
    double offsetX = 2.0;
    double offsetY = 3.0;
    double offsetZ = 4.0;

    // Apply translation to each vertex of the cube
    for (auto& vertex : vertices) {
        translate(vertex, offsetX, offsetY, offsetZ);
    }

    // Print translated coordinates of the cube's vertices
    cout << "Translated Cube Vertices:" << endl;
    for (const auto& vertex : vertices) {
        cout << "(" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")" << endl;
    }

    return 0;
}
