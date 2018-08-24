// @subject:
// @diff:

#pragma unroll
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;

int t, n, h[256], x, v[N];

inline void fast_read() {
  x = 0;
  char ch = getchar_unlocked();
  if (ch < '0' or ch > '9') ch = getchar_unlocked();
  while (ch >= '0' and ch <= '9') {
    x = (x<<3)+(x<<1)+ch-'0';
    ch = getchar_unlocked();
  }
}

inline void print(unsigned char n) {
  char c[4];
  c[0] = '0'+(n%10); n /= 10;
  c[1] = '0'+(n%10); n /= 10;
  if (n) putchar('0'+n);
  putchar(c[1]);
  putchar(c[0]);
}

int main() {
  fast_read();
  t = x;
  while (t--) {
    fast_read();
    n = x;

    for (int i = 0; i < n; i++) fast_read(), h[x]++;

    for (unsigned char i = 20; i <= 230; i++) while (h[i]) {
      print(i);
      if (n > 1) putchar(' ');

      h[i]--;
      n--;
    }

    putchar('\n');
  }
  return 0;
}
