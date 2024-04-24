#include <graphics.h>
#include <iostream>

using namespace std;

int compute_code(int x, int y, int X_MIN, int X_MAX, int Y_MIN, int Y_MAX)
{
    int code = 0;
    if (x < X_MIN)
        code |= 1; 
    else if (x > X_MAX)
        code |= 2; 
    if (y < Y_MIN)
        code |= 4; 
    else if (y > Y_MAX)
        code |= 8; 
    return code;
}


void mid_point_clip(int x1, int y1, int x2, int y2, int X_MIN, int X_MAX, int Y_MIN, int Y_MAX)
{
    int code1 = compute_code(x1, y1, X_MIN, X_MAX, Y_MIN, Y_MAX);
    int code2 = compute_code(x2, y2, X_MIN, X_MAX, Y_MIN, Y_MAX);
    bool accept = false;

    while (true)
    {
        if (!(code1 | code2)){
            accept = true;
            break;
        }else if (code1 & code2){
            break;
        }
        else{
            int code_out = code1 ? code1 : code2;

            int x = x1;
            int y = y1;

            if (code_out & 8){
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            }
            else if (code_out & 4){
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            }
            else if (code_out & 2){
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            }
            else if (code_out & 1){
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }


            if (code_out == code1){
                x1 = x;
                y1 = y;
                code1 = compute_code(x1, y1, X_MIN, X_MAX, Y_MIN, Y_MAX);
            }
            else{
                x2 = x;
                y2 = y;
                code2 = compute_code(x2, y2, X_MIN, X_MAX, Y_MIN, Y_MAX);
            }
        }
    }

    if (accept)
    {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
    else{
        cout << "Line segment is outside the viewport and rejected." << endl;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int X_MIN, X_MAX, Y_MIN, Y_MAX;
  
    cout << "Viewport coordinates (x_min x_max y_min y_max) : ";
    cin >> X_MIN >> X_MAX >> Y_MIN >> Y_MAX;
    
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
   
    int x1, y1, x2, y2;
    
    cout << "Coordinates of the line segment (x1 y1 x2 y2) : ";
    cin >> x1 >> y1 >> x2 >> y2;

    setcolor(YELLOW);
    line(x1, y1, x2, y2);

    mid_point_clip(x1, y1, x2, y2, X_MIN, X_MAX, Y_MIN, Y_MAX);

    return 0;
}
