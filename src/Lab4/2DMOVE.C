// WAP TO IMPLEMENT THE TRANSLATION, ROTATION AND SCALING BY USING 3*3 MATRIX.

#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

typedef struct Point {
  int x;
  int y;
} point;

void drawTraingle(point p1, point p2, point p3) {
  line(p1.x, p1.y, p2.x, p2.y);
  line(p2.x, p2.y, p3.x, p3.y);
  line(p1.x, p1.y, p3.x, p3.y);
}

// res store the result after matrix multiplication
void mat_mul(float a[3][3], float b[3][3], float res[3][3]) {
  int i, j, k;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      res[i][j] = 0;
      for (k = 0; k < 3; k++) {
        res[i][k] = a[i][k] * b[k][i];
      }
    }
  }
}

point transpose(point p, float x, float y) {
  float M1[3][3], M2[3][3]
  M1 = {{1, 0, x}, {0, 1, y}, {0, 0, 1}};
  M2 = {{p.x, 0, 0}, {p.y, 0, 0}, {1, 0, 0}};
  float result[3][3];
  mat_mul(M1, M2, result);
  point final = {result[0][0], result[1][0]};
  return final;
}
point rotate(point p, float angle) {
  float angleInradian,cosAngle,sinAngle
  angleInradian  = angle * (PI / 180.00);
  cosAngle = cos(angleInradian);
  sinAngle = sin(angleInradian);
  float M1[3][3],M2[3][3];
  M1= {
      {cosAngle, -sinAngle, 0}, {sinAngle, cosAngle, 0}, {0, 0, 1}};
  M2 = {{p.x, 0, 0}, {p.y, 0, 0}, {1, 0, 0}};
  float result[3][3];
  mat_mul(M1, M2, result);
  point final = {result[0][0], result[1][0]};
  return final;
}
point scaling(point p, float x, float y) {
  float M1[3][3],M2[3][3];
  M1  = {{x, 0, 0}, {0, y, 0}, {1, 0, 0}};
  M2 = {{p.x, 0, 0}, {p.y, 0, 0}, {1, 0, 0}};
  float result[3][3];
  mat_mul(M1, M2, result);
  point final = {result[0][0], result[1][0]};
  return final;
}

int main() {
  point p1,p2,p3;
	p1  = {100, 10};
 p2 = {250, 10};
 p3 = {150, 250};
  point pt1, pt2, pt3;
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gd, &gmode, "C:\\TURBOC3\\BGI");
  drawTraingle(p1, p2, p3);
  float transposePoint = 50;
  pt1 = transpose(p1, transposePoint, transposePoint);
  pt2 = transpose(p2, transposePoint, transposePoint);
  pt3 = transpose(p3, transposePoint, transposePoint);
  drawTraingle(pt1, pt2, pt3);

  float scalingPoint = 2;
  pt1 = scaling(p1, scalingPoint, scalingPoint);
  pt3 = scaling(p2, scalingPoint, scalingPoint);
  pt3 = scaling(p3, scalingPoint, scalingPoint);
  drawTraingle(pt1, pt2, pt3);

  float angle = 30;
  pt1 = rotate(p1, angle);
  pt2 = rotate(p2, angle);
  pt3 = rotate(p3, angle);
  drawTraingle(pt1, pt2, pt3);

  getch();
  closegraph();
  return 0;
}