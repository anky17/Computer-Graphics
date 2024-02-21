#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int maxX, maxY, midX, midY;

typedef struct point {
  float x;
  float y;
} Point;

void drawAxes() {
  line(midX, 0, midX, maxY);
  outtextxy(midX + 2, 0, (char *)"Y");
  line(0, midY, maxX, midY);
  outtextxy(maxX - 10, midY - 12, (char *)"X");
}

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

void normalizeAndDraw(Point P1, Point P2, Point P3, int mvCoeff, char *str) {
  P1.x = midX - P1.x;
  P2.x = midX - P2.x;
  P3.x = midX - P3.x;
  P1.y = midY - P1.y;
  P2.y = midY - P2.y;
  P3.y = midY - P3.y;
  drawTriangle(P1, P2, P3);
  outtextxy(P1.x, P1.y + mvCoeff, str);
}

Point XReflect(Point P) {
  float m1[3][3] = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
  float m2[3][3] = {{P.x, 0, 0}, {P.y, 0, 0}, {1, 0, 0}};
  float res[3][3];
  matMul(m1, m2, res);
  Point result = {res[0][0], res[1][0]};
  return result;
}

Point YReflect(Point P) {
  float m1[3][3] = {{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  float m2[3][3] = {{P.x, 0, 0}, {P.y, 0, 0}, {1, 0, 0}};
  float res[3][3];
  matMul(m1, m2, res);
  Point result = {res[0][0], res[1][0]};
  return result;
}

int main() {
  Point P1 = {250, 15}, P2 = {25, 50}, P3 = {45, 80};
  Point Pt1, Pt2, Pt3;
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, (char *)"C:/TurboC3/BGI");
  maxX = getmaxx();
  maxY = getmaxy();
  midX = maxX / 2;
  midY = maxY / 2;
  drawAxes();
  normalizeAndDraw(P1, P2, P3, -35, (char *)"Original");
  Pt1 = YReflect(P1);
  Pt2 = YReflect(P2);
  Pt3 = YReflect(P3);
  normalizeAndDraw(Pt1, Pt2, Pt3, -30, (char *)"Y reflect");
  Pt1 = XReflect(P1);
  Pt2 = XReflect(P2);
  Pt3 = XReflect(P3);
  normalizeAndDraw(Pt1, Pt2, Pt3, 30, (char *)"X reflect");
  getch();
  closegraph();
  return 0;
}
