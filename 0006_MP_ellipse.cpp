#include <iostream>
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void drawEllipseMidpoint(int xc, int yc, int rx, int ry) {
    int rxSq = rx*rx;
    int rySq = ry*ry;
    int x = 0, y=ry;
    int p;
    int px=0, py= 2*rxSq*y;

    // Region 1
    p = round(rySq - (rxSq*ry) + (0.25*rxSq));
    while (px < py) {
        putpixel(xc + x, yc - y, GREEN);
        putpixel(xc - x, yc - y, GREEN);
        putpixel(xc + x, yc + y, GREEN);
        putpixel(xc - x, yc + y, GREEN);

        x++;
        px = px + 2*rySq;
        if (p<0)
            p = p + rySq + px;
        else {
            y--;
            py = py - 2 * rxSq;
            p = p + rySq + px - py;
        }
    }

    // Region 2
    p = round(rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq);
    while (y>0) {
        putpixel(xc + x, yc - y, GREEN);
        putpixel(xc - x, yc - y, GREEN);
        putpixel(xc + x, yc + y, GREEN);
        putpixel(xc - x, yc + y, GREEN);

        y--;
        py = py - 2*rxSq;
        if (p>0)
            p = p + rxSq - py;
        else {
            x++;
            px = px + 2*rySq;
            p = p + rxSq - py + px;
        }
    }
}

int main() {
    int xc, yc, rx, ry;
    cout << "Enter the center coordinates (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter the radii (rx, ry): ";
    cin >> rx >> ry;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawEllipseMidpoint(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}
