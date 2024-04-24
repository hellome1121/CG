#include<iostream>
#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main(){
    int radius;
    cout<<"Enter Radius : ";
    cin>>radius;

    int gd=DETECT,gm,color; 
    initgraph(&gd, &gm,NULL);
    int x=0,y=radius;
    double p= 5/4 - radius;

    vector<pair<int,int> > v;
    v.push_back({x,y});

    while(x<y){
        if(p<0){
            p=p + 2*x + 3;
            x++;
            v.push_back({x,y});
            v.push_back({y,x});
            v.push_back({y,-x});
            v.push_back({x,-y});
            v.push_back({-x,-y});
            v.push_back({-y,-x});
            v.push_back({-y,x});
            v.push_back({-x,y});
        }else{
            p=p + 2*(x-y) + 5;
            x++;
            y--;
            v.push_back({x,y});
            v.push_back({y,x});
            v.push_back({y,-x});
            v.push_back({x,-y});
            v.push_back({-x,-y});
            v.push_back({-y,-x});
            v.push_back({-y,x});
            v.push_back({-x,y});
        }
    }
    for(int i=0;i<v.size();i++){
        putpixel(100+v[i].first,100+v[i].second,YELLOW);
    }
    getch();  
    closegraph();
    return 0;
}