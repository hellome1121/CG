#include <iostream>
#include <graphics.h>
using namespace std;

void drawLineMidpoint(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1, y = y1;
    putpixel(x, y, YELLOW);
    int p = 2*dy - dx;

    for (int k=0; k<dx; k++) {
        if (p < 0) {   
            x++;
            p += 2 * dy;
        } else {
            x++;
            y++;
            p += 2 * (dy-dx);
        }
        delay(100); 
        putpixel(x, y, YELLOW);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x1, y1, x2, y2;

    cout << "Enter values of x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter values of x2 and y2: ";
    cin >> x2 >> y2;

    drawLineMidpoint(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}