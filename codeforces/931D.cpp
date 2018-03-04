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

int n, p[N], h[N], cnt[N];
vector<int> adj[N];

void dfs(int u) {
  cnt[h[u]] ^= 1;
  for (int v : adj[u]) {
    h[v] = h[u]+1;
    dfs(v);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) scanf("%d", &p[i]), adj[p[i]].push_back(i);

  dfs(1);

  sort(h+1,h+n+1);
  int ans = 0;
  for (int i = 0; i <= n; i++) ans += cnt[i];
  printf("%d\n", ans);

  return 0;
}
