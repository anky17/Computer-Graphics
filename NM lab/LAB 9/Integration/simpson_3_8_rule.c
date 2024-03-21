#include <math.h>
#include <stdio.h>

// Function to integrate
double function(double x) { return cos(x); }

double simpsonsRule(double a, double b, int n) {
  double h = (b - a) / n;
  double sum = function(a) + function(b);
  for (int i = 1; i < n; i++) {
    double x = a + i * h;
    if (i % 3 == 0)
      sum += 2 * function(x);
    else
      sum += 3 * function(x);
  }
  return (3 * h / 8.0) * sum;
}
int main() {
  double a = 1.0;
  double b = 3.0;
  int n = 4;  // no of intervals(must be even)
  double result = simpsonsRule(a, b, n);
  printf("Numerical integration result: %lf\n", result);
  return 0;
}
