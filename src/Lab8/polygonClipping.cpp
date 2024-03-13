// 1. Implementation & Demonstration of Sutherland Hudgeman polygon clipping
// algorithm. [note: show polygons with segments that are partially clipped by
// each boundary].

#include <graphics.h>
#include <stdio.h>

// Windows coordinate
#define X_MIN 100
#define X_MAX 300
#define Y_MIN 100
#define Y_MAX 200

// Main function
int main() {
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, (char *)"C:/TurboC3/BGI");

  rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
  getch();
  closegraph();
  return 0;
}
