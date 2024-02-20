#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PI 3.14

typedef struct point{
    float x;
    float y;
} Point;

void matMul(float a[3][3], float b[3][3], float mul[3][3]){
    int i, j, k;
    for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			mul[i][j] = 0;
			for (k = 0; k < 3; k++){
				mul[i][j] += a[i][k] * b[k][j];
			}
		}
    }
}

void drawTriangle(Point P1, Point P2, Point P3){
    line(P1.x, P1.y, P2.x, P2.y);
    line(P2.x, P2.y, P3.x, P3.y);
    line(P1.x, P1.y, P3.x, P3.y);
}

Point translate(Point P, float x, float y){
    float m1[3][3] = {{1, 0, x}, {0, 1, y}, {0, 0, 1}};
    float m2[3][3] = {{P.x, 0, 0}, {P.y, 0, 0}, {1, 0, 0}};
    float res[3][3];
    matMul(m1, m2, res);
    Point result = {res[0][0], res[1][0]};
    return result;
}

Point rotate(Point P, float angle){
    float angleRad = angle * (PI / 180.0);
    float cos_angle = cos(angleRad), sin_angle = sin(angleRad);
    float m1[3][3] = {{cos_angle, -sin_angle, 0}, {sin_angle, cos_angle, 0}, {0, 0, 1}};
    float m2[3][3] = {{P.x, 0, 0}, {P.y, 0, 0}, {1, 0, 0}};
    float res[3][3];
    matMul(m1, m2, res);
    Point result = {res[0][0], res[1][0]};
    return result;
}

Point scaling(Point P, float x, float y){
    float m1[3][3] = {{x, 0, 0}, {0, y, 0}, {0, 0, 1}};
    float m2[3][3] = {{P.x, 0, 0}, {P.y, 0, 0}, {1, 0, 0}};
    float res[3][3];
    matMul(m1, m2, res);
    Point result = {res[0][0], res[1][0]};
    return result;
}

int main(){
    Point P1 = {50, 15}, P2 = {250, 105}, P3 = {150, 200};
    Point Pt1, Pt2, Pt3;
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:/TurboC3/BGI");
    drawTriangle(P1, P2, P3);
	outtextxy(P1.x, P1.y-5, "Original");
    float t = 50;
    Pt1 = translate(P1, t, t);
    Pt2 = translate(P2, t, t);
    Pt3 = translate(P3, t, t);
    drawTriangle(Pt1, Pt2, Pt3);
	outtextxy(Pt1.x, Pt1.y-5, "Translated");
    float s = 2;
    Pt1 = scaling(P1, s, s);
    Pt2 = scaling(P2, s, s);
    Pt3 = scaling(P3, s, s);
    drawTriangle(Pt1, Pt2, Pt3);
	outtextxy(Pt1.x, Pt1.y-5, "Scaled");
    float a = 30;
    Pt1 = rotate(P1, a);
    Pt2 = rotate(P2, a);
    Pt3 = rotate(P3, a);
    drawTriangle(Pt1, Pt2, Pt3);
	outtextxy(Pt1.x, Pt1.y-5, "Rotated");
    getch();
    closegraph();
    return 0;
}