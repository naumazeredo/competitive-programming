#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n;
int a[60][60];
int p[60];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);

  if (n == 2) {
    printf("2 1\n"); return 0;
  }

  for (int i = 0; i < n; ++i) p[i] = n;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int c = 0;
      for (int k = 0; k < n; ++k) {
        if (a[j][k] == i) c++;
      }
      if (c == n-i) {
        p[j] = i;
        break;
      }
    }
  }

  for (int i = 0; i < n; ++i) printf("%d ", p[i]);
  printf("\n");
  return 0;
}
