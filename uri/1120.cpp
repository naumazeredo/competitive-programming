#include <bits/stdc++.h>
using namespace std;

int d, n;
char s[200];

int main() {
  while (1) {
    scanf("%d%s", &d, s);
    n = strlen(s);

    if (d == 0 and n == 1 and s[0] == '0') break;

    int m = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == d+'0') continue;
      if (!m and s[i] == '0') continue;
      printf("%c", s[i]);
      m=1;
    }

    if (!m) printf("0");
    printf("\n");
  }

  return 0;
}
