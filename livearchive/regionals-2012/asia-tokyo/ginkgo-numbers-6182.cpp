#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  int m, n;
  scanf("%d", &t);
  for (int tt = 0; tt < t; ++tt) {
    scanf("%d%d", &m, &n);

    int d = 0;
    int mm = max(abs(m), abs(n));
    for (int i = -mm; i <= mm; ++i) {
      for (int j = -mm; j <= mm; ++j) {
        if (!i && !j) continue;
        if ((i*m + j*n) % (i*i+j*j) == 0 &&
            (i*n - j*m) % (i*i+j*j) == 0) {
          d++;
        }
      }
    }

    printf("%c\n", d==8 ? 'P' : 'C');
  }

  return 0;
}
