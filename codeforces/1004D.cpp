// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e6+5;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int t, b, v[N], v2[N];

void test(int n, int m, int x, int y) {
  if (x < 1 or x > n or y < 1 or y > m) return;
  memset(v2, 0, sizeof v2);
  vector<vector<int>> dist(n+1, vector<int>(m+1, INF));
  queue<pii> q;
  dist[x][y] = 0;
  q.push({ x, y });

  while (q.size()) {
    int ux = q.front().st;
    int uy = q.front().nd;
    q.pop();
    v2[dist[ux][uy]]++;

    for (int i = 0; i < 4; i++) {
      int vx = ux + dx[i];
      int vy = uy + dy[i];
      if (vx >= 1 and vx <= n and vy >= 1 and vy <= m and dist[vx][vy] > dist[ux][uy]+1) {
        dist[vx][vy] = dist[ux][uy]+1;
        q.push({ vx, vy });
      }
    }
  }

  for (int i = 0; i <= b; i++) if (v[i] != v2[i]) return;

  printf("%d %d\n%d %d\n", n, m, x, y);
  exit(0);
}

int main() {
  scanf("%d", &t);
  for (int k, i = 0; i < t; i++) scanf("%d", &k), v[k]++, b = max(b, k);
  int x = -1;
  for (int i = 1; ; i++) if (v[i] != 4*i) { x = i; break; }

  for (int n = 1; 1ll*n*n <= t; n++) if (t%n == 0) {
    int m = t/n;
    int y = n + m - b - x;
    test(n, m, x, y);
    test(m, n, x, y);
  }

  printf("-1\n");

  return 0;
}
