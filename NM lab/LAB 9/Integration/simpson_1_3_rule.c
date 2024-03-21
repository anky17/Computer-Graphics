#include <math.h>
#include <stdio.h>
// Function to integrate
double function(double x) { return cos(x); }

double simpsonsRule(double a, double b, int n) {
  double h = (b - a) / n;
  double sum = function(a) + function(b);
  for (int i = 1; i < n; i++) {
    double x = a + i * h;
    if (i % 2 == 0)
      sum += 2 * function(x);
    else
      sum += 4 * function(x);
  }
  return (h / 3.0) * sum;
}
int main() {
  double a = 1.0;

  double b = 3.0;
  int n = 4;  // Number of subintervals (must be even)
  double result = simpsonsRule(a, b, n);
  printf("Numerical integration result: %lf\n", result);
  return 0;
}
