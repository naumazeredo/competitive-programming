// @subject:
// @diff:

#define and &&
#define or ||

#pragma unroll
#pragma GCC optimize ("O3")
#pragma GCC optimize("expensive-optimizations")

//#include <bits/stdc++.h>
#include <stdio.h>
//using namespace std;

#define N 3000001

int t, n, h[256], x, p;
char s[4*N], c[4];
int i, ch;

int main() {
  x = 0;
  ch = getchar_unlocked();
  if (ch < '0' or ch > '9') ch = getchar_unlocked();
  while (ch >= '0' and ch <= '9') {
    x = (x<<3)+(x<<1)+ch-'0';
    ch = getchar_unlocked();
  }
  t = x;
  while (t--) {
    x = 0;
    ch = getchar_unlocked();
    if (ch < '0' or ch > '9') ch = getchar_unlocked();
    while (ch >= '0' and ch <= '9') {
      x = (x<<3)+(x<<1)+ch-'0';
      ch = getchar_unlocked();
    }
    n = x;

    for (i = 0; i < n; i++) {
      x = 0;
      ch = getchar_unlocked();
      if (ch < '0' or ch > '9') ch = getchar_unlocked();
      while (ch >= '0' and ch <= '9') {
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar_unlocked();
      }
      h[x]++;
    }

    p = 0;
    for (i = 20; i <= 230; i++) while (h[i]) {
      x = i;
      c[0] = x%10; x /= 10;
      c[1] = x%10; x /= 10;

      if (x) s[p++] = '0'+x;
      s[p++] = '0'+c[1];
      s[p++] = '0'+c[0];

      if (n > 1) s[p++] = ' ';

      h[i]--;
      n--;
    }

    for (i = 0; i < p; i++) putchar_unlocked(s[i]);
    putchar_unlocked('\n');
  }
  return 0;
}
