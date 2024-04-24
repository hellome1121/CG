#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
using namespace std;

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;
    int p = 2*dy - dx;

    if (x1 > x2){
        x = x2;
        y = y2;
        x2 = x1;
    }else{
        x = x1;
        y = y1;
    }

    putpixel(x,y,YELLOW);

    for (int k = 0; k<dx; k++) {
        if (p < 0) {
            x++;
            p = p + 2*dy;
        }
        else {
            x++;
            y++;
            p = p + 2*(dy-dx);
        }
        putpixel(x, y, YELLOW);
        delay(100);
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    initgraph(&gd, &gm, NULL);

    cout << "Enter values of x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter values of x2 and y2: ";
    cin >> x2 >> y2;

    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
