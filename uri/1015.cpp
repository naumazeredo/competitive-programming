#include <bits/stdc++.h>
using namespace std;

#define y1 y15613851

double x1, y1, x2, y2;

int main() {
  scanf("%lf%lf", &x1, &y1);
  scanf("%lf%lf", &x2, &y2);

  double dx = x1-x2;
  double dy = y1-y2;

  printf("%.4lf\n", sqrt(dx*dx + dy*dy));
  return 0;
}
