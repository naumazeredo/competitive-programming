#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 5e4+5;

char s[N], t[N];
ull occ[256][N], l[N];

int main() {
  scanf("%s%s", s, t);
  int n = strlen(s);
  int m = strlen(t);

  if (n < m) swap(s, t), swap(n, m);

  int w = (n+63)>>6;

  ull ss = 1;
  for (int i = 0, j = 0; i < n; i++) {
    occ[(int)s[i]][j] |= ss;
    ss <<= 1;
    if (!ss) ss++, j++;
  }

  /*
  for (char i = 'a'; i <= 'z'; i++) {
    printf("%c: ", i);
    for (int j = 0; j < w; j++)
      printf("%s", bitset<64>(occ[i][j]).to_string().c_str());
    printf("\n");
  }
  */

  ull b1, b2, c;
  for (int i = 0; i < m; i++) {
    b1 = 1, b2 = 0;
    for (int j = 0; j < w; j++) {
      ull u = l[j] | occ[(int)t[i]][j];
      c = l[j] >> 63;
      ull v = u - ((l[j] << 1) | (b1 + b2));
      b1 = c; b2 = (v > u);
      l[j] = u & (~v);

    }
    /*
    printf("%d: ", i);
    for (int j = 0; j < w; j++)
      printf("%s", bitset<64>(l[j]).to_string().c_str());
    printf("\n");
    */
  }

  int ans = 0;
  for (int i = 0; i < w; i++)
    for (; l[i]; ans++)
      l[i] &= l[i]-1;

  printf("%d\n", ans);
  return 0;
}
