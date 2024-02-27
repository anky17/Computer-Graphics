#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PI 3.14

typedef struct point {
  float x;
  float y;
} Point;

void matMul(float a[3][3], float b[3][3], float mul[3][3]) {
  int i, j, k;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      mul[i][j] = 0;
      for (k = 0; k < 3; k++) {
        mul[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

void drawTriangle(Point P1, Point P2, Point P3, char *str) {
  line(P1.x, P1.y, P2.x, P2.y);
  line(P2.x, P2.y, P3.x, P3.y);
  line(P1.x, P1.y, P3.x, P3.y);
  outtextxy(P3.x - 10, P3.y + 12, str);
}

Point pivotRotate(Point P, Point Arb, float angle) {
  float temp[3][3], temp2[3][3], res[3][3];  // TEMP AND RESULT MATRICES

  float angleRad = angle * (PI / 180.0);
  float cosAngle = cos(angleRad), sinAngle = sin(angleRad);
  // MATRIX CONTAINING THE POINTS
  float PointM[3][3] = {{P.x, 0, 0}, {P.y, 0, 0}, {1, 0, 0}};
  // MATRIX TO TRANSLATE TO ORIGIN
  float trMat[3][3] = {{1, 0, -Arb.x}, {0, 1, -Arb.y}, {0, 0, 1}};
  // MATRIX TO ROTATE
  float rotMat[3][3] = {
      {cosAngle, -sinAngle, 0}, {sinAngle, cosAngle, 0}, {0, 0, 1}};
  // MATRXIX TO TRANSLATE BACK TO OG POSITION
  float RvtrMat[3][3] = {{1, 0, Arb.x}, {0, 1, Arb.y}, {0, 0, 1}};

  matMul(trMat, PointM, temp);
  matMul(rotMat, temp, temp2);
  matMul(RvtrMat, temp2, res);

  Point result = {res[0][0], res[1][0]};
  return result;
}

int main() {
  Point P1 = {50, 30}, P2 = {250, 105}, P3 = {150, 200};
  Point Pt1, Pt2, Pt3;
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, (char *)"C:/TurboC3/BGI");
  drawTriangle(P1, P2, P3, (char *)"Original");

  Point Arb = {240, 300};
  putpixel(Arb.x, Arb.y, 7);
  outtextxy(Arb.x, Arb.y + 5, (char *)"Pivot");
  // PIVOT ROTATE
  Pt1 = pivotRotate(P1, Arb, 60);
  Pt2 = pivotRotate(P2, Arb, 60);
  Pt3 = pivotRotate(P3, Arb, 60);
  drawTriangle(Pt1, Pt2, Pt3, (char *)"Rotated");

  getch();
  closegraph();
  return 0;
}
