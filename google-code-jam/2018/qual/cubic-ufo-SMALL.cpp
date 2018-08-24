#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld PI = acos(-1.0L);

int t;
ld a, x, y;

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    printf("Case #%d:\n", tt);
    scanf("%Lf", &a);

    ld ang = PI/4.0L - acos(a/sqrt(2.0L));
    ld s = sin(ang), c = cos(ang);

    printf("0.0 0.0 0.5\n");

    x = 0.5, y = 0;
    printf("%.12Lf %.12Lf 0.0\n", x*c-y*s, x*s+y*c);

    x = 0, y = 0.5;
    printf("%.12Lf %.12Lf 0.0\n", x*c-y*s, x*s+y*c);
  }
  return 0;
}
