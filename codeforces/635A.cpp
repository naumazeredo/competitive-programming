#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int r, c, n, k;
int g[20][20];

int main() {
  scanf("%d%d%d%d", &r, &c, &n, &k);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    y--, x--;
    g[x][y] = 1;
  }

  int ans = 0;
  for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
    for (int y = i; y < r; ++y) for (int x = j; x < c; ++x) {
      int c = 0;
      for (int a = i; a <= y; ++a) for (int b = j; b <= x; ++b)
        c += g[a][b];
      if (c >= k) ans++;
    }

  printf("%d\n", ans);

  return 0;
}
