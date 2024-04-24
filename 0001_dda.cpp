#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;

void dda(int x1,int y1, int x2,int y2){
  float dx=x2-x1;
  float dy=y2-y1;

  int steps=((abs(dx))>=abs(dy))?abs(dx):abs(dy);

  float xi=dx/steps;
  float yi=dy/steps;
  float x=x1,y=y1;

  for(int i=0;i<steps;i++){
    putpixel(floor(x),floor(y),YELLOW);
     x+=xi;
     y+=yi;
     delay(100);
  }
}

int main(){
  int gd=DETECT,gm;
  int x1,x2,y1,y2;
  cout<<"Enter x1 and y1: ";
  cin>>x1>>y1;
  cout<<"Enter x2 and y2: ";
  cin>>x2>>y2;

  initgraph(&gd,&gm,NULL);
  dda(x1,y1,x2,y2);
  getch();
  closegraph();
}