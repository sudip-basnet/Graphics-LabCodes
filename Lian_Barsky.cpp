#include <iostream>
#include<cmath>
#include <graphics.h>

using namespace std;

bool liangBarskyClip(int x0, int y0, int x1, int y1, int x_min, int y_min, int x_max, int y_max, int &new_x0, int &new_y0, int &new_x1, int &new_y1) {
    float t0 = 0.0f, t1 = 1.0f;
    int dx = x1 - x0, dy = y1 - y0;
    float p, q, r;

    for (int edge = 0; edge < 4; edge++) {
        if (edge == 0) { p = -dx; q = -(x_min - x0); }
        if (edge == 1) { p = dx; q = (x_max - x0); }
        if (edge == 2) { p = -dy; q = -(y_min - y0); }
        if (edge == 3) { p = dy; q = (y_max - y0); }

        if (p == 0 && q < 0) return false;

        r = q / p;
        if (p < 0) {
            if (r > t1) return false;
            if (r > t0) t0 = r;
        } else if (p > 0) {
            if (r < t0) return false;
            if (r < t1) t1 = r;
        }
    }

    new_x0 = x0 + t0 * dx;
    new_y0 = y0 + t0 * dy;
    new_x1 = x0 + t1 * dx;
    new_y1 = y0 + t1 * dy;
    return true;
}

void drawClippedLine(int x0, int y0, int x1, int y1) {
    int x_min = 100, y_min = 100, x_max = 300, y_max = 300;
    int new_x0, new_y0, new_x1, new_y1;

    rectangle(x_min, y_min, x_max, y_max);

    if (liangBarskyClip(x0, y0, x1, y1, x_min, y_min, x_max, y_max, new_x0, new_y0, new_x1, new_y1)) {
        setcolor(WHITE);
        line(new_x0, new_y0, new_x1, new_y1);
    }
}

int main() {
    int gd = DETECT, gm,x1,y1,x2,y2;
    initgraph(&gd, &gm, "");

    cout<<"Enter the end points of line: ";
    cout<<"x1: ";
    cin>>x1;
    cout<<"y1: ";
    cin>>y1;
    cout<<"x2: ";
    cin>>x2;
    cout<<"y2: ";
    cin>>y2;

    drawClippedLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

