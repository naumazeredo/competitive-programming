#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int t, q;
int p[100005];

int gcd(int a, int b) {
  return b?gcd(b,a%b):a;
}

int main() {
  while (scanf("%d%d", &t, &q) != EOF && t && q) {
    scanf("%d", &p[0]);
    int m = 0;
    for (int i = 1; i < t; ++i) {
      scanf("%d", &p[i]);
      m = gcd(m, abs(p[i]-p[i-1]));
    }
    m*=2;

    for (int i = 0; i < q; ++i) {
      int s, d;
      scanf("%d%d", &s, &d);

      if (i) printf(" ");
      if (s==d) { printf("Y"); continue; }
      int ok=0;
      for (int j = 0; j < t; ++j) {
        if (abs(d-p[j])==abs(p[j]-s)) {
          ok=1; printf("Y"); break;
        }
      }
      if (ok) continue;

      if (m>0 && (d-s)%m==0) {printf("Y"); continue;}
      printf("N");
    }
    printf("\n");
  }
  return 0;
}
