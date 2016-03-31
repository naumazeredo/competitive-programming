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

int n, t, x;
int adj[44444];
int vis[44444];

int dfs(int u) {
  vis[u] = 1;
  if (u == t) return 1;
  if (!vis[adj[u]]) if (dfs(adj[u])) return 1;
  return 0;
}

int main() {
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n-1; ++i) scanf("%d", &x), adj[i]=i+x;

  printf("%s\n", dfs(1) ? "YES" : "NO");
  return 0;
}
