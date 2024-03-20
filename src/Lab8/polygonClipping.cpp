#include <graphics.h>
#include <stdio.h>

int points[8][2] = {
    {20, 20},    // Vertex 1
    {100, 20},   // Vertex 2
    {180, 60},   // Vertex 3
    {180, 140},  // Vertex 4
    {100, 180},  // Vertex 5
    {20, 140},   // Vertex 6
    {20, 60},    // Vertex 7
    {60, 100}    // Vertex 8
};

// It is temp array used to store the new coordinates of the vertices
// after clipping.
int nw[8][2] = {{0}};

int leftClip(int, int);
int topClip(int, int);
int rightClip(int, int);
int bottomClip(int, int);

int main() {
  int gd = DETECT, gm;
  int xmin, ymin, xmax, ymax, n, i;
  initgraph(&gd, &gm, NULL);

  // Clipping window coordinates
  xmin = 40;
  ymin = 40;
  xmax = 160;
  ymax = 160;

  rectangle(xmin, ymin, xmax, ymax);
  for (i = 0; i < 8; i++) {
    line(points[i][0], points[i][1], points[(i + 1) % 8][0],
         points[(i + 1) % 8][1]);
  }

  // Clipping
  int result = leftClip(8, xmin);
  result = topClip(result, ymin);
  result = rightClip(result, xmax);
  result = bottomClip(result, ymax);

  // delay(3000);
  // cleardevice();

  // rectangle(xmin, ymin, xmax, ymax);
  // for (i = 0; i < result; i++)
  //   line(points[i][0], points[i][1], points[(i + 1) % result][0],
  //        points[(i + 1) % result][1]);

  getch();
  closegraph();
  return 0;
}

int leftClip(int limit, int xmin) {
  int i, j = 0, x1, y1, x2, y2;
  float m;
  for (i = 0; i < limit; i++) {
    x1 = points[i][0];
    y1 = points[i][1];
    x2 = points[(i + 1) % limit][0];
    y2 = points[(i + 1) % limit][1];
    if (x2 - x1)
      m = (y2 - y1) * 1.0 / (x2 - x1);
    else
      m = 0;
    if (x1 < xmin && x2 < xmin) continue;
    if (x1 >= xmin && x2 >= xmin) {
      nw[j][0] = x2;
      nw[j++][1] = y2;
      continue;
    }
    if (x1 >= xmin && x2 < xmin) {
      nw[j][0] = xmin;
      nw[j++][1] = y1 + m * (xmin - x1);
      continue;
    }
    if (x1 < xmin && x2 >= xmin) {
      nw[j][0] = xmin;
      nw[j++][1] = y1 + m * (xmin - x1);
      nw[j][0] = x2;
      nw[j++][1] = y2;
    }
  }

  for (i = 0; i < j; i++) {
    points[i][0] = nw[i][0];
    points[i][1] = nw[i][1];
    nw[i][0] = nw[i][1] = 0;
  }

  if (j < limit)
    for (; i < limit; i++) points[i][0] = points[i][1] = 0;

  return j;
}

int topClip(int limit, int ymin) {
  int i, j = 0, x1, y1, x2, y2;
  float m;
  for (i = 0; i < limit; i++) {
    x1 = points[i][0];
    y1 = points[i][1];
    x2 = points[(i + 1) % limit][0];
    y2 = points[(i + 1) % limit][1];
    if (x2 - x1)
      m = (y2 - y1) * 1.0 / (x2 - x1);
    else
      m = 0;

    if (y1 < ymin && y2 < ymin) continue;
    if (y1 >= ymin && y2 >= ymin) {
      nw[j][0] = x2;
      nw[j++][1] = y2;
      continue;
    }
    if (y1 >= ymin && y2 < ymin) {
      nw[j][0] = x1 + (ymin - y1) / m;
      nw[j++][1] = ymin;
      continue;
    }
    if (y1 < ymin && y2 >= ymin) {
      nw[j][0] = x1 + (ymin - y1) / m;
      nw[j++][1] = ymin;
      nw[j][0] = x2;
      nw[j++][1] = y2;
    }
  }

  for (i = 0; i < j; i++) {
    points[i][0] = nw[i][0];
    points[i][1] = nw[i][1];
    nw[i][0] = nw[i][1] = 0;
  }

  if (j < limit)
    for (; i < limit; i++) points[i][0] = points[i][1] = 0;

  return j;
}

int rightClip(int limit, int xmax) {
  int i, j = 0, x1, y1, x2, y2;
  float m;
  for (i = 0; i < limit; i++) {
    x1 = points[i][0];
    y1 = points[i][1];
    x2 = points[(i + 1) % limit][0];
    y2 = points[(i + 1) % limit][1];
    if (x2 - x1)
      m = (y2 - y1) * 1.0 / (x2 - x1);
    else
      m = 0;

    if (x1 > xmax && x2 > xmax) continue;
    if (x1 <= xmax && x2 <= xmax) {
      nw[j][0] = x2;
      nw[j++][1] = y2;
      continue;
    }
    if (x1 <= xmax && x2 > xmax) {
      nw[j][0] = xmax;
      nw[j++][1] = y1 + m * (xmax - x1);
      continue;
    }
    if (x1 > xmax && x2 <= xmax) {
      nw[j][0] = xmax;
      nw[j++][1] = y1 + m * (xmax - x1);
      nw[j][0] = x2;
      nw[j++][1] = y2;
    }
  }

  for (i = 0; i < j; i++) {
    points[i][0] = nw[i][0];
    points[i][1] = nw[i][1];
    nw[i][0] = nw[i][1] = 0;
  }

  if (j < limit)
    for (; i < limit; i++) points[i][0] = points[i][1] = 0;

  return j;
}

int bottomClip(int limit, int ymax) {
  int i, j = 0, x1, y1, x2, y2;
  float m;
  for (i = 0; i < limit; i++) {
    x1 = points[i][0];
    y1 = points[i][1];
    x2 = points[(i + 1) % limit][0];
    y2 = points[(i + 1) % limit][1];
    if (x2 - x1)
      m = (y2 - y1) * 1.0 / (x2 - x1);
    else
      m = 0;

    if (y1 > ymax && y2 > ymax) continue;
    if (y1 <= ymax && y2 <= ymax) {
      nw[j][0] = x2;
      nw[j++][1] = y2;
      continue;
    }
    if (y1 <= ymax && y2 > ymax) {
      nw[j][0] = x1 + (ymax - y1) / m;
      nw[j++][1] = ymax;
      continue;
    }
    if (y1 > ymax && y2 <= ymax) {
      nw[j][0] = x1 + (ymax - y1) / m;
      nw[j++][1] = ymax;
      nw[j][0] = x2;
      nw[j++][1] = y2;
    }
  }

  for (i = 0; i < j; i++) {
    points[i][0] = nw[i][0];
    points[i][1] = nw[i][1];
    nw[i][0] = nw[i][1] = 0;
  }

  if (j < limit)
    for (; i < limit; i++) points[i][0] = points[i][1] = 0;
  return j;
}
