#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, a[N], o[N];
map<int, int> m;
int adj[N], vis[N];

void dfs(int u, vi& v) {
  v.pb(u);
  vis[u] = 1;
  if (!vis[adj[u]]) dfs(adj[u], v);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), o[i] = i, m[a[i]] = i;
  sort(o,o+n,[](int i, int j){ return a[i] < a[j]; });

  vector<vi> ans;
  for (int i = 0; i < n; i++) adj[o[i]] = i;
  for (int i = 0; i < n; i++) if (!vis[i]) {
    vi v;
    dfs(i, v);
    ans.pb(v);
  }

  printf("%d\n", (int)ans.size());
  for (vi v : ans) {
    printf("%d", (int)v.size());
    for (int x : v) printf(" %d", x+1);
    printf("\n");
  }

  return 0;
}
