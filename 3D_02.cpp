#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    double x, y, z;
};

// Rotation functions for x, y, and z axes
void rotateX(Point& p, double theta) {
    double newY = p.y * cos(theta) - p.z * sin(theta);
    double newZ = p.y * sin(theta) + p.z * cos(theta);
    p.y = newY;
    p.z = newZ;
}

void rotateY(Point& p, double theta) {
    double newX = p.x * cos(theta) + p.z * sin(theta);
    double newZ = -p.x * sin(theta) + p.z * cos(theta);
    p.x = newX;
    p.z = newZ;
}

void rotateZ(Point& p, double theta) {
    double newX = p.x * cos(theta) - p.y * sin(theta);
    double newY = p.x * sin(theta) + p.y * cos(theta);
    p.x = newX;
    p.y = newY;
}

// Concatenate rotation matrices for x, y, and z axes
vector<vector<double>> rotationMatrix(double thetaX, double thetaY, double thetaZ) {
    vector<vector<double>> matrixX = {
        {1, 0, 0},
        {0, cos(thetaX), -sin(thetaX)},
        {0, sin(thetaX), cos(thetaX)}
    };

    vector<vector<double>> matrixY = {
        {cos(thetaY), 0, sin(thetaY)},
        {0, 1, 0},
        {-sin(thetaY), 0, cos(thetaY)}
    };

    vector<vector<double>> matrixZ = {
        {cos(thetaZ), -sin(thetaZ), 0},
        {sin(thetaZ), cos(thetaZ), 0},
        {0, 0, 1}
    };

    // Concatenate matrices: Z * Y * X
    vector<vector<double>> result(3, vector<double>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrixZ[i][k] * matrixY[k][j];
            }
        }
    }
    vector<vector<double>> finalResult(3, vector<double>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                finalResult[i][j] += result[i][k] * matrixX[k][j];
            }
        }
    }

    return finalResult;
}

int main() {
    // Initial coordinates of the cube's vertices
    vector<Point> vertices = {{-1, -1, -1}, {-1, -1, 1}, {-1, 1, -1}, {-1, 1, 1},
                               {1, -1, -1}, {1, -1, 1}, {1, 1, -1}, {1, 1, 1}};

    // Angles for rotation around x, y, and z axes (in radians)
    double thetaX = M_PI / 4;  // Rotation around x-axis
    double thetaY = M_PI / 3;  // Rotation around y-axis
    double thetaZ = M_PI / 6;  // Rotation around z-axis

    // Compute rotation matrix
    vector<vector<double>> rotationMat = rotationMatrix(thetaX, thetaY, thetaZ);

    // Apply rotation to each vertex of the cube
    for (int i = 0; i < 8; ++i) {
        double x = vertices[i].x;
        double y = vertices[i].y;
        double z = vertices[i].z;

        // Apply rotation using matrix multiplication
        vertices[i].x = rotationMat[0][0] * x + rotationMat[0][1] * y + rotationMat[0][2] * z;
        vertices[i].y = rotationMat[1][0] * x + rotationMat[1][1] * y + rotationMat[1][2] * z;
        vertices[i].z = rotationMat[2][0] * x + rotationMat[2][1] * y + rotationMat[2][2] * z;
    }

    // Print rotated coordinates of the cube's vertices
    cout << "Rotated Cube Vertices:" << endl;
    for (const auto& vertex : vertices) {
        cout << "(" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")" << endl;
    }

    return 0;
}
