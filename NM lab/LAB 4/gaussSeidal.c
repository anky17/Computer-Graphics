// WAP TO IMPLEMENT THE GAUSS SEIDAL METHOD.

#include <conio.h>
#include <math.h>
#include <stdio.h>

/* Arrange systems of linear quations to be solved in diagonally dominant form
and form equation for each unknown and define here
*/
/* Arranging given system of linear equations in diagonally dominant form:
20x + y - 2z = 17
3x + 20y -z = -18
2x - 3y + 20z = 25

*/
/* Defining function */

#define f1(x, y, z) (17 - y + 2 * z) / 20
#define f2(x, y, z) (-18 - 3 * x + z) / 20
#define f3(x, y, z) (25 - 2 * x + 3 * y) / 20

// #define f1(x, y, z) (11.19 - z - y) / 10
// #define f2(x, y, z) (28.08 - x - z) / 10
// #define f3(x, y, z) (35.61 + x - y) / 10

int main() {
  float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3,
        e;  // declaring variable with initial guess...
  int count = 1;
  printf("Enter tolerable error:\n");
  scanf("%f", &e);
  printf("\nCount\tx\ty\tz\n");

  do {
    /* Calculation */
    x1 = f1(x0, y0, z0);
    y1 = f2(x1, y0, z0);
    z1 = f3(x1, y1, z0);

    printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);
    /* Error */
    e1 = fabs(x0 - x1);  // fabs is absolute value..
    e2 = fabs(y0 - y1);
    e3 = fabs(z0 - z1);

    count++;  // iteration count updated

    /* Set value for next iteration */
    x0 = x1;
    y0 = y1;
    z0 = z1;

  } while (e1 > e && e2 > e && e3 > e);

  printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n", x1, y1,
         z1);  // precision upto 3 decimal places
  return 0;
}