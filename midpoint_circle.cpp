#include<iostream>
#include<cmath>
#include<graphics.h>

using namespace std;

void display_pixels(int x,int y, int xc,int yc){
    putpixel(x+xc,y+yc,RED);
    putpixel(-x+xc,y+yc,RED);
    putpixel(-x+xc,-y+yc,RED);
    putpixel(x+xc,-y+yc,RED);
    putpixel(y+yc,x+xc,RED);
    putpixel(y+yc,-x+xc,RED);
    putpixel(-y+yc,-x+xc,RED);
    putpixel(-y+yc,x+xc,RED);
}

int main(){
    int gd = DETECT, gm;
    int r,xc,yc,pk,x,y;
    initgraph(&gd,&gm,"C:\MinGW\BGI");
    cout<<"Enter the radius of the circle.";
    cin>>r;
    cout<<"Enter the center of the circle.";
    cin>>xc>>yc;
    pk = 1-r;
    x = 0;
    y = r;
    putpixel(xc,yc+r,RED);

    while(x<y){
        if (pk < 0){
            x++;
            pk = pk + 2*x +1;
        }
        else{
            x++;
            y--;
            pk = pk + 2*x - 2*y +1;
        }
        display_pixels(x,y,xc,yc);

    }
    getch();
    closegraph();
    return 0;

}
