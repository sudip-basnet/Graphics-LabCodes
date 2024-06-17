#include<iostream>
#include<cmath>
#include<graphics.h>

using namespace std;

int main(){
    int gd = DETECT, gm;
    int x,y,x1,x2,y1,y2,dx,dy,pk;
    initgraph(&gd,&gm,"C:\MinGW\BGI");
    cout<<"Enter the values of start points\n";
    cin>>x1>>y1;
    cout<<"Enter the values of end points\n";
    cin>>x2>>y2;
    dx = x2-x1;
    dy = y2-y1;

    putpixel(x1,y1,RED);
    x = x1;
    y = y1;

    if(dy<=dx){
        pk = 2*dy - dx;
        for (int i = 0; i < dx; i++){
          if (pk<0){
            x++;
            putpixel(x,y,RED);
            pk = pk + 2*dy;
          }
          else{
            x++;
            y++;
            putpixel(x,y,RED);
            pk = pk + 2*dy - 2*dx;
          }
        }
    }
    else{
        pk = 2*dx - dy;
        for (int i = 0; i < dy ; i++){
            if(pk<0){
                y++;
                putpixel(x,y,RED);
                pk = pk + 2*dx;
            }
            else{
                y++;
                x++;
                putpixel(x,y,RED);
                pk = pk + 2*dx -2*dy;
            }
        }

    }
    getch();
    closegraph();
    return 0;
}
