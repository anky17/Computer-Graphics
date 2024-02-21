#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int maxX, maxY, midX, midY;

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

void drawTriangle(Point P1, Point P2, Point P3) {
  line(P1.x, P1.y, P2.x, P2.y);
  line(P2.x, P2.y, P3.x, P3.y);
  line(P1.x, P1.y, P3.x, P3.y);
}

void normalize(Point P1, Point P2, Point P3, int mvCoeff, char *str) {
  drawTriangle(P1, P2, P3);
  outtextxy(P3.x + mvCoeff, P3.y + mvCoeff, str);
}

Point XShear(Point P, float shX) {
  float m1[3][3] = {{1, shX, 0}, {0, 1, 0}, {0, 0, 1}};
  float m2[3][3] = {{P.x, 0, 0}, {P.y, 0, 0}, {1, 0, 0}};
  float res[3][3];
  matMul(m1, m2, res);
  Point result = {res[0][0], res[1][0]};
  return result;
}

Point YShear(Point P, float shY) {
  float m1[3][3] = {{1, 0, 0}, {shY, 1, 0}, {0, 0, 1}};
  float m2[3][3] = {{P.x, 0, 0}, {P.y, 0, 0}, {1, 0, 0}};
  float res[3][3];
  matMul(m1, m2, res);
  Point result = {res[0][0], res[1][0]};
  return result;
}

int main() {
  Point P1 = {0, 0}, P2 = {0, 100}, P3 = {50, 100};
  Point Pt1, Pt2, Pt3;
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, (char *)"C:/TurboC3/BGI");
  maxX = getmaxx();
  maxY = getmaxy();
  midX = maxX / 2;
  midY = maxY / 2;

  normalize(P1, P2, P3, -30, (char *)"Original");
  Pt1 = YShear(P1, 2);
  Pt2 = YShear(P2, 2);
  Pt3 = YShear(P3, 2);

  normalize(Pt1, Pt2, Pt3, -20, (char *)"Y Shear");
  Pt1 = XShear(P1, 2);
  Pt2 = XShear(P2, 2);
  Pt3 = XShear(P3, 2);
  normalize(Pt1, Pt2, Pt3, -20, (char *)"X Shear");

  getch();
  closegraph();
  return 0;
}
