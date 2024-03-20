// WAP TO IMPLEMENT WINDOWS TO VIEWPORT TRANSFORMATION.

#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

// Global variable declaration
int W_xmax, W_ymax, W_xmin, W_ymin;
int V_xmax, V_ymax, V_xmin, V_ymin;
float sx, sy;

typedef struct point {
  float x;
  float y;
} Point;

void drawTriangle(Point P1, Point P2, Point P3) {
  line(P1.x, P1.y, P2.x, P2.y);
  line(P2.x, P2.y, P3.x, P3.y);
  line(P1.x, P1.y, P3.x, P3.y);
}

Point viewPortTransformation(Point P) {
  sx = (float)(V_xmax - V_xmin) / (W_xmax - W_xmin);
  sy = (float)(V_ymax - V_ymin) / (W_ymax - W_ymin);
  Point result;
  result.x = V_xmin + (float)((P.x - W_xmin) * sx);
  result.y = V_ymin + (float)((P.y - W_ymin) * sy);
  return result;
}

int main() {
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, (char *)"C:/TurboC3/BGI");

  // Window
  W_xmax = 350, W_ymax = 350, W_xmin = 10, W_ymin = 30;
  rectangle(W_xmin, W_ymin, W_xmax, W_ymax);
  outtextxy(W_xmin, W_ymin - 20, (char *)"Window");
  // drawing a triangle
  Point P1 = {200, 100}, P2 = {40, 80}, P3 = {180, 200};
  drawTriangle(P1, P2, P3);

  // Viewport
  V_xmin = 400, V_ymin = 80, V_xmax = 550, V_ymax = 350;
  rectangle(V_xmin, V_ymin, V_xmax, V_ymax);
  outtextxy(V_xmin, V_ymin - 20, (char *)"Viewport");
  Point Pt1, Pt2, Pt3;
  // Function call to transform window to viewport
  Pt1 = viewPortTransformation(P1);
  Pt2 = viewPortTransformation(P2);
  Pt3 = viewPortTransformation(P3);
  drawTriangle(Pt1, Pt2, Pt3);

  getch();
  closegraph();
  return 0;
}
