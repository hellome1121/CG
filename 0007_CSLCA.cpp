#include <iostream>
#include <graphics.h>
using namespace std;

// above_below_right_left
const int INSIDE = 0; 
const int LEFT = 1;   
const int RIGHT = 2;  
const int BOTTOM = 4; 
const int TOP = 8;    

int computeCode(double x, double y, double x_min, double y_min, double x_max, double y_max) {
    int code = INSIDE;

    if (x < x_min)      
        code |= LEFT;
    else if (x > x_max) 
        code |= RIGHT;
    if (y < y_min)      
        code |= BOTTOM;
    else if (y > y_max) 
        code |= TOP;

    return code;
}

// Implementing Cohen-Sutherland algorithm
void cohenSutherlandClip(double x1, double y1, double x2, double y2, double x_min, double y_min, double x_max, double y_max) {
    int code1 = computeCode(x1, y1, x_min, y_min, x_max, y_max);
    cout<<"bit code of (x1,y1) in decimal form : "<< code1<<endl;
    int code2 = computeCode(x2, y2, x_min, y_min, x_max, y_max);
    cout<<"bit code of (x2,y2) in decimal form  : "<< code2<<endl;

    bool accept = false;

    while (true) {
        if ((code1 || code2) == 0) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            double x, y;
            int outcode;

            // At least one endpoint is outside the rectangle, pick it.
            outcode = code1 ? code1 : code2;

            // Find intersection point
            if (outcode & TOP) {
                x = x1 + (x2-x1) * (y_max-y1) / (y2-y1);
                y = y_max;
            } else if (outcode & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (outcode & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (outcode & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Replace point outside rectangle by intersection point
            if (outcode == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, x_min, y_min, x_max, y_max);
                cout<<"verify code1 : "<<code1<<endl;
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, x_min, y_min, x_max, y_max);
                cout<<"verify code2 : "<<code2<<endl;
            }
        }
    }
    if (accept) {
        cout << "Line accepted from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
        line(int(x1), int(y1), int(x2), int(y2));
    } else {
        cout << "Line rejected\n";
    }
}

int main() {
    double x_min, y_min, x_max, y_max;
    double x1, y1, x2, y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Enter the coordinates of the clipping window (x_min, y_min, x_max, y_max): ";
    cin >> x_min >> y_min >> x_max >> y_max;

    rectangle(x_min, y_min, x_max, y_max);

    cout << "Enter the coordinates of the line (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    setcolor(RED); 
    line(int(x1), int(y1), int(x2), int(y2));

    setcolor(WHITE); 
    cohenSutherlandClip(x1, y1, x2, y2, x_min, y_min, x_max, y_max);

    getch(); 
    closegraph(); 


    return 0;
}