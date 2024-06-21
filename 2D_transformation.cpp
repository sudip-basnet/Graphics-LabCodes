#include <iostream>
#include <cmath>
#include <graphics.h>

using namespace std;

void draw(int v1[3], int v2[3], int v3[3], int v4[3])
{
    line(v1[0], v1[1], v2[0], v2[1]);
    line(v2[0], v2[1], v3[0], v3[1]);
    line(v3[0], v3[1], v4[0], v4[1]);
    line(v4[0], v4[1], v1[0], v1[1]);
}

void mult(int Final[3][3], int trans[3][3], int ver[3][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                Final[i][j] += (int)(trans[i][k] * ver[k][j] + 0.5);
            }
        }
    }
}

void mult(int final[3], int trans[3][3], int ver[3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            final[i] += (int)(trans[i][j] * ver[j] + 0.5);
        }
    }
}

void translation(int v1[3], int v2[3], int v3[3], int v4[3], int tx, int ty)
{
    int t[3][3];
    int fv1[3] = {0}, fv2[3] = {0}, fv3[3] = {0}, fv4[3] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                t[i][j] = 1;
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    t[0][2] = tx;
    t[1][2] = ty;

    mult(fv1, t, v1);
    mult(fv2, t, v2);
    mult(fv3, t, v3);
    mult(fv4, t, v4);

    draw(fv1, fv2, fv3, fv4);
}

void rotation(int v1[3], int v2[3], int v3[3], int v4[3], float angle)
{
    int t1[3][3], t2[3][3], t3[3][3], tx, ty, f[3][3] = {0}, f1[3][3] = {0};
    int fv1[3] = {0}, fv2[3] = {0}, fv3[3] = {0}, fv4[3] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                t1[i][j] = 1;
                t2[i][j] = 1;
                t3[i][j] = 1;
            }
            else
            {
                t1[i][j] = 0;
                t2[i][j] = 0;
                t3[i][j] = 0;
            }
        }
    }
    angle = (3.14 / 180) * angle;

    tx = (v1[0] + v2[0] + v3[0] + v4[0]) / 4;
    ty = (v1[1] + v2[1] + v3[1] + v4[1]) / 4;

    t1[0][2] = -tx;
    t1[1][2] = -ty;

    t2[0][0] = (int)(cos(angle) + 0.5);
    t2[0][1] = angle < 0 ? (int)(-1 * sin(angle) + 0.5) : (int)(-1 * sin(angle) - 0.5);
    t2[1][0] = angle < 0 ? (int)(sin(angle) - 0.5) : (int)(sin(angle) + 0.5);
    t2[1][1] = (int)(cos(angle) + 0.5);

    t3[0][2] = tx;
    t3[1][2] = ty;

    mult(f1, t2, t1);
    mult(f, t3, f1);

    mult(fv1, f, v1);
    mult(fv2, f, v2);
    mult(fv3, f, v3);
    mult(fv4, f, v4);

    draw(fv1, fv2, fv3, fv4);
}

void scaling(int v1[3], int v2[3], int v3[3], int v4[3], float sx, float sy)
{
    int tx, ty, fv1[3] = {0}, fv2[3] = {0}, fv3[3] = {0}, fv4[3] = {0};

    tx = (v1[0] + v2[0] + v3[0] + v4[0]) / 4;
    ty = (v1[1] + v2[1] + v3[1] + v4[1]) / 4;

    fv1[0] = (int)(tx + ((v1[0] - tx) * sx));
    fv2[0] = (int)(tx + ((v2[0] - tx) * sx));
    fv3[0] = (int)(tx + ((v3[0] - tx) * sx));
    fv4[0] = (int)(tx + ((v4[0] - tx) * sx));

    fv1[1] = (int)(ty + ((v1[1] - ty) * sy));
    fv2[1] = (int)(ty + ((v2[1] - ty) * sy));
    fv3[1] = (int)(ty + ((v3[1] - ty) * sy));
    fv4[1] = (int)(ty + ((v4[1] - ty) * sy));

    draw(fv1, fv2, fv3, fv4);
}

void shearing(int v1[3], int v2[3], int v3[3], int v4[3], float shx, float shy)
{
    int t[3][3];
    int fv1[3] = {0}, fv2[3] = {0}, fv3[3] = {0}, fv4[3] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                t[i][j] = 1;
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    t[0][1] = (int)shx;
    t[1][0] = (int)shy;

    mult(fv1, t, v1);
    mult(fv2, t, v2);
    mult(fv3, t, v3);
    mult(fv4, t, v4);

    draw(fv1, fv2, fv3, fv4);
}

void reflection(int v1[3], int v2[3], int v3[3], int v4[3])
{
    int t[3][3];
    int fv1[3] = {0}, fv2[3] = {0}, fv3[3] = {0}, fv4[3] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                t[i][j] = 1;
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    t[0][1] = 1;
    t[1][0] = 1;
    t[0][0] = 0;
    t[1][1] = 0;

    mult(fv1, t, v1);
    mult(fv2, t, v2);
    mult(fv3, t, v3);
    mult(fv4, t, v4);

    draw(fv1, fv2, fv3, fv4);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\MingGW\BGI");

    int v1[3], v2[3], v3[3], v4[3], tx, ty;
    float angle, sx, sy, shx, shy;
    char in;

    v1[2] = 1;
    v2[2] = 1;
    v3[2] = 1;
    v4[2] = 1;

    char x = 'y';

    while (x == 'y')
    {
        cout << "Enter the vertices of the rectangle:\n";
        cout << "(x1,y1):";
        cin >> v1[0] >> v1[1];
        cout << "(x2,y2):";
        cin >> v2[0] >> v2[1];
        cout << "(x3,y3):";
        cin >> v3[0] >> v3[1];
        cout << "(x4,y4):";
        cin >> v4[0] >> v4[1];
        draw(v1, v2, v3, v4);
        cout << "Enter the transformation to be performed.\n";
        cout << " t for translation\n s for scaling\n r for rotation\n a for shearing\n f for reflection\n";
        cin >> in;

        switch (in)
        {
        case 't':
            cout << "Enter the translation along x-direction: ";
            cin >> tx;
            cout << "Enter the translation along y-direction: ";
            cin >> ty;

            translation(v1, v2, v3, v4, tx, ty);
            break;

        case 'r':
            cout << "Enter the angle of rotation: ";
            cin >> angle;
            rotation(v1, v2, v3, v4, angle);
            break;

        case 's':
            cout << "Enter the scaling factor along x-direction: ";
            cin >> sx;
            cout << "Enter the scaling factor along y-direction: ";
            cin >> sy;
            scaling(v1, v2, v3, v4, sx, sy);
            break;

        case 'a':
            cout << "Enter the shearing factor along x-direction: ";
            cin >> shx;
            cout << "Enter the shearing factor along y-direction: ";
            cin >> shy;
            shearing(v1, v2, v3, v4, shx, shy);
            break;

        case 'f':
            reflection(v1, v2, v3, v4);
            break;

        default:
            cout << "Enter the valid input";
            break;
        }

        cout << "Do you want to continue?";
        cin >> x;
        if (x == 'y')
        {
            cleardevice();
        }
        else
        {
            break;
        }
    }
    getch();
    closegraph();

    return 0;
}
