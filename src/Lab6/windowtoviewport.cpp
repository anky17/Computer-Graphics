// WAP TO IMPLEMENT WINDOWS TO VIEWPORT TRANSFORMATION.
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

// Global variable declaration
int W_xmax, W_ymax, W_xmin, W_ymin;
int V_xmax, V_ymax, V_xmin, V_ymin;
float sx, sy;
int x = 200, y = 100, x1 = 40, x2 = 180, y1 = 80, y2 = 200;

void drawTriangle(int x, int y, int x1, int y1, int x2, int y2) {
  line(x, y, x1, y1);
  line(x1, y1, x2, y2);
  line(x2, y2, x, y);
}

void viewPortTransformation() {
  sx = (float)(V_xmax - V_xmin) / (W_xmax - W_xmin);
  sy = (float)(V_ymax - V_ymin) / (W_ymax - W_ymin);
  x = V_xmin + (float)((x - W_xmin) * sx);
  x1 = V_xmin + (float)((x1 - W_xmin) * sx);
  x2 = V_xmin + (float)((x2 - W_xmin) * sx);
  y = V_ymin + (float)((y - W_ymin) * sy);
  y1 = V_ymin + (float)((y1 - W_ymin) * sy);
  y2 = V_ymin + (float)((y2 - W_ymin) * sy);
  drawTriangle(x, y, x1, y1, x2, y2);
}

int main() {
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, (char *)"C:/TurboC3/BGI");

  // Window
  W_xmax = 350, W_ymax = 350, W_xmin = 10, W_ymin = 30;
  rectangle(W_xmin, W_ymin, W_xmax, W_ymax);
  outtextxy(W_xmin, W_ymin - 20, (char *)"Window");
  // drawing a triangle
  drawTriangle(x, y, x1, y1, x2, y2);

  // Viewport
  V_xmin = 400, V_ymin = 80, V_xmax = 550, V_ymax = 350;
  rectangle(V_xmin, V_ymin, V_xmax, V_ymax);
  outtextxy(V_xmin, V_ymin - 20, (char *)"Viewport");

  // Function call to transform window to viewport
  viewPortTransformation();

  getch();
  closegraph();
  return 0;
}