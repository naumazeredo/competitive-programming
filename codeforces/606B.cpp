#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int m[505][505];

int x, y, i, j;

int main() {
  scanf("%d%d%d%d", &x, &y, &i, &j);

  int tot = x*y-1;
  memset(m, 0, sizeof(m));

  vector<int> a;
  a.push_back(1);
  m[i][j]=1;

  char c;
  while (scanf(" %c", &c) != EOF) {
    if (c == 'U') { if (--i < 1) i=1; }
    else if (c == 'D') { if (++i > x) i=x; }
    else if (c == 'L') { if (--j < 1) j=1; }
    else { if (++j > y) j=y; }

    int f = 0;
    if (m[i][j]==0) m[i][j]=1, tot--, f=1;

    a.push_back(f);
  }

  if (tot > 0) a[a.size()-1] += tot;

  for (int i = 0; i < a.size(); ++i)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}
