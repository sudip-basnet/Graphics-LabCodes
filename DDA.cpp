#include<iostream>
#include<cmath>
#include<graphics.h>

using namespace std;

int main(){
    int gd = DETECT,gm;
    int x1,y1,x2,y2,stepsize,dx,dy;
    float x,y,xinc,yinc;
    initgraph(&gd,&gm,"C:\MinGW\BGI");
    cout<<"Digital Differential Line Drawing Algorithm\n";
    cout<<"Put the values of x1 and y1\n";
    cin>>x1>>y1;
    cout<<"Put the values of x2 and y2\n";
    cin>>x2>>y2;
    dx = x2-x1;
    dy = y2-y1;
    x = x1;
    y = y1;
    if(abs(dy)>abs(dx)){
        stepsize = abs(dy);
    }
    else{
        stepsize = abs(dx);
    }
    xinc = dx/(float)stepsize;
    yinc = dy/(float)stepsize;
    putpixel(x,y,WHITE);
    for(int i=0;i<stepsize;i++){
        x = x + xinc;
        y = y + yinc;
        putpixel(round(x),round(y),WHITE);
    }
    getch();
    closegraph();
    return 0;

}
