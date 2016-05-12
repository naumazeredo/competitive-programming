#include <bits/stdc++.h>
using namespace std;

int n, t;
char s[2][100005];
int a[100005];
int b[2];

int main() {
  scanf("%d%d", &n, &t);
  scanf("%s", s[0]);
  scanf("%s", s[1]);

  memset(a, -1, sizeof(a));
  b[0]=0; b[1]=0;

  for (int i = 0; i < n; ++i) {
    if (s[0][i] != s[1][i]) {
      if (b[0] == b[1]) a[i]=0, b[0]++;
      else a[i]=1, b[1]++;
    }
  }

  for (int i = 0; i < n && b[0] < t && b[1] < t; ++i)
    if (s[0][i] == s[1][i])
      a[i]=2, b[0]++, b[1]++;

  for (int i = 0; i < n && b[0] < t; ++i)
    if (a[i]==1)
      a[i]=2, b[0]++;

  for (int i = 0; i < n && b[1] < t; ++i)
    if (a[i]==0)
      a[i]=2, b[1]++;

  if (b[0] == t && b[1] == t) {
    for (int i = 0; i < n; ++i) {
      if (a[i] == 0 || a[i] == -1) printf("%c", s[0][i]);
      if (a[i] == 1) printf("%c", s[1][i]);
      if (a[i] == 2) {
        for (char c='a'; c<='z'; ++c) {
          if (c != s[0][i] && c != s[1][i]) {
            printf("%c", c); break;
          }
        }
      }
    }
    printf("\n");
    return 0;
  }

  printf("-1\n");

  return 0;
}
