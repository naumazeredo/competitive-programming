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
const int N = 2e5+5;

int n, p[N], b, s, vis[N], k;

void dfs(int u) {
  vis[u] = 1;
  if (!vis[p[u]]) dfs(p[u]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &p[i]), p[i]--;
  for (int i = 0; i < n; ++i) scanf("%d", &b), s+=b;
  for (int i = 0; i < n; ++i) if (!vis[i]) k++, dfs(i);

  int ans = (k>1?k:0) + !(s%2);
  printf("%d\n", ans);
  return 0;
}
