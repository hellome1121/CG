#include <graphics.h>
#include <iostream>
#include <vector>

using namespace std;

void liang_barsky_clip(int x1, int y1, int x2, int y2, int X_MIN, int X_MAX, int Y_MIN, int Y_MAX)
{
    float p[4], q[4], u1 = 0.0, u2 = 1.0;
    int dx = x2 - x1, dy = y2 - y1;
    p[0] = -dx; 
    q[0] = x1 - X_MIN;
    
    p[1] = dx;  
    q[1] = X_MAX - x1;
    
    p[2] = -dy; 
    q[2] = y1 - Y_MIN;
    
    p[3] = dy;  
    q[3] = Y_MAX - y1;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0)
                return; 
        } else {
            float r = q[i] / p[i];
            if (p[i] < 0)
                u1 = max(u1, r);
            else
                u2 = min(u2, r);
        }
    }

    if (u1 > u2) return; 

    int nx1 = x1 + u1 * dx;
    int ny1 = y1 + u1 * dy;
    int nx2 = x1 + u2 * dx;
    int ny2 = y1 + u2 * dy;

    setcolor(GREEN);
    line(nx1, ny1, nx2, ny2);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int X_MIN = 50, X_MAX = 300, Y_MIN = 50, Y_MAX = 300;

    setcolor(WHITE);
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    int n = 5;
    vector<pair<int, int>> vertices = {{100, 100}, {300, 50}, {500, 200}, {400, 350}, {200, 350}};

    setcolor(RED);
    for (int i = 0; i < n; i++) {
        line(vertices[i].first, vertices[i].second, 
             vertices[(i + 1) % n].first, vertices[(i + 1) % n].second);
    }

    for (int i = 0; i < n; i++) {
        liang_barsky_clip(vertices[i].first, vertices[i].second, 
                          vertices[(i + 1) % n].first, vertices[(i + 1) % n].second, 
                          X_MIN, X_MAX, Y_MIN, Y_MAX);
    }

    delay(350000);
    closegraph();
    return 0;
}