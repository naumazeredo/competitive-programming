#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e5+5;

int t, n, r[N][2], c[N], vis[N];

int dfs(int u) {
  if (vis[u]) return 0;

  if (c[u]) c[u]--;
  else {
    vis[u]++;
    if (!dfs(r[u][0])) return 0;
    if (!dfs(r[u][1])) return 0;
    vis[u]--;
  }

  return 1;
}

int add() {
  for (int i = 1; i <= n; i++) vis[i] = 0;
  return dfs(1);
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &r[i][0], &r[i][1]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);

    int ans = 0;
    while (add()) ans++;

    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
