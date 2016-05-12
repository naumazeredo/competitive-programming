#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int p, d, n;

int main() {
  scanf("%d", &p);
  while (p--) {
    char s[1000];
    int v[1000];

    scanf("%d", &d);
    getchar();
    int p = 0;
    while (scanf("%c", &s[p]) != EOF && s[p]!='\n') p++;
    s[p] = '\0';
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

    printf("%d ", d);
    int pos = 0;
    for (int i = 0; i < n; ++i) {
      pos = (strlen(s)+pos+v[i])%strlen(s);
      printf("%c", s[pos]);
    }
    printf("\n");
  }
  return 0;
}
