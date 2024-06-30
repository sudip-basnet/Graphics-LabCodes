#include <iostream>
#include<cmath>
#include <graphics.h>

using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int x_min, y_min, x_max, y_max;

int computeOutCode(int x, int y) {
    int code = INSIDE;

    if (x < x_min) code |= LEFT;
    else if (x > x_max) code |= RIGHT;
    if (y < y_min) code |= BOTTOM;
    else if (y > y_max) code |= TOP;

    return code;
}

void cohenSutherlandClip(int x0, int y0, int x1, int y1) {
    int outcode0 = computeOutCode(x0, y0);
    int outcode1 = computeOutCode(x1, y1);
    bool accept = false;

    while (true) {
        if ((outcode0 | outcode1) == 0) {
            accept = true;
            break;
        } else if (outcode0 & outcode1) {
            break;
        } else {
            int x, y;
            int outcodeOut = outcode0 ? outcode0 : outcode1;

            if (outcodeOut & TOP) {
                x = x0 + (x1 - x0) * (y_max - y0) / (y1 - y0);
                y = y_max;
            } else if (outcodeOut & BOTTOM) {
                x = x0 + (x1 - x0) * (y_min - y0) / (y1 - y0);
                y = y_min;
            } else if (outcodeOut & RIGHT) {
                y = y0 + (y1 - y0) * (x_max - x0) / (x1 - x0);
                x = x_max;
            } else if (outcodeOut & LEFT) {
                y = y0 + (y1 - y0) * (x_min - x0) / (x1 - x0);
                x = x_min;
            }

            if (outcodeOut == outcode0) {
                x0 = x;
                y0 = y;
                outcode0 = computeOutCode(x0, y0);
            } else {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(x1, y1);
            }
        }
    }

    if (accept) {
        setcolor(WHITE);
        line(x0, y0, x1, y1);
    }
}

int main() {
    int gd = DETECT, gm,x1,x2,y1,y2;
    initgraph(&gd, &gm, "");

    x_min = 100; y_min = 100; x_max = 300; y_max = 300;

    rectangle(x_min, y_min, x_max, y_max);
    cout<<"Enter the end points of line: ";
    cout<<"x1: ";
    cin>>x1;
    cout<<"y1: ";
    cin>>y1;
    cout<<"x2: ";
    cin>>x2;
    cout<<"y2: ";
    cin>>y2;

    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

