#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const long double EPS = 1e-9;

int n, a, h[N];

int main() {
  while (scanf("%d%d", &n, &a) != EOF and n and a) {
    int sum = 0;
    for (int i = 0; i < n; i++) scanf("%d", &h[i]), sum += h[i];

    if (sum == a) {
      printf(":D\n");
      continue;
    }
    if (sum < a) {
      printf("-.-\n");
      continue;
    }

    long double lo = 0, hi = 1e18;
    for (int i = 0; i < 100; i++) {
      long double mid = (lo+hi)/2;

      long double area = 0;
      for (int j = 0; j < n; j++)
        if (mid <= h[j]) area += h[j] - mid;

      if (area <= a) hi = mid;
      else lo = mid;
    }

    long double ans = (lo+hi)/2;
    printf("%.4f\n", (double)ans);
  }

  return 0;
}
