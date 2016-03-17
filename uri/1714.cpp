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
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int n;
char g[105][105];
char v[105][105];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf(" %s", g[i]);

  int ans = INF;
  for (int i = 0; i < (1<<10); ++i) {
    bitset<10> b(i);

    memset(v, 0, sizeof(v));

    queue<int> qx, qy, qd;
    qx.push(0); qy.push(0); qd.push(1);

    while (!qx.empty()) {
      int x = qx.front(); qx.pop();
      int y = qy.front(); qy.pop();
      int d = qd.front(); qd.pop();

      v[y][x] = 1;

      if (b[tolower(g[y][x])-'a'] == (g[y][x] >= 'a' and g[y][x] <= 'j')) {
        if (y == n-1 and x == n-1) {
          ans = min(ans, d);
          break;
        }

        if (x > 0   and !v[y][x-1]) qx.push(x-1), qy.push(y), qd.push(d+1);
        if (x < n-1 and !v[y][x+1]) qx.push(x+1), qy.push(y), qd.push(d+1);
        if (y > 0   and !v[y-1][x]) qx.push(x), qy.push(y-1), qd.push(d+1);
        if (y < n-1 and !v[y+1][x]) qx.push(x), qy.push(y+1), qd.push(d+1);
      }
    }
  }

  printf("%d\n", ans!=INF?ans:-1);
  return 0;
}
