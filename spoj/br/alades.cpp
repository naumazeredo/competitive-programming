#include <bits/stdc++.h>
using namespace std;

int h0, m0, h1, m1;

int main() {
  while (scanf("%d%d%d%d", &h0, &m0, &h1, &m1), h0 or m0 or h1 or m1) {
    int v0 = h0 * 60 + m0;
    int v1 = h1 * 60 + m1;
    if (v1 < v0) v1 += 24*60;
    printf("%d\n", v1-v0);
  }
  return 0;
}
