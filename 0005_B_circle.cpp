#include <iostream>
#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main() {
    int radius;
    cout << "Enter Radius : ";
    cin >> radius;

    int gd = DETECT, gm, color;
    initgraph(&gd, &gm, NULL);

    int x = 0, y = radius;
    int d = 3 - 2*radius;

    vector<pair<int, int>> v;
    v.push_back({x, y});

    while (x <= y) {
        if (d <= 0) {
            d = d + 4*x + 6;
        } else {
            d = d + 4*(x-y) + 10;
            y--;
        }
        x++;
        v.push_back({x, y});
        v.push_back({y, x});
        v.push_back({y, -x});
        v.push_back({x, -y});
        v.push_back({-x, -y});
        v.push_back({-y, -x});
        v.push_back({-y, x});
        v.push_back({-x, y});
    }

    for (int i = 0; i < v.size(); i++) {
        putpixel(100 + v[i].first, 100 + v[i].second, RED);
        delay(50);
    }

    getch();
    closegraph();
    return 0;
}
