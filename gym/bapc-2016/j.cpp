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
const int N = 1e2+5;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
pii s[N], t[N];
int x, b[N], vis[N];
vector<int> adj[N];

ll dist2(int i, int j) {
  ll dx = s[i].st - t[j].st;
  ll dy = s[i].nd - t[j].nd;
  return abs(dx) + abs(dy);
}

bool match(int u) {
  if (vis[u] == x) return 0;
  vis[u] = x;
  for (int v : adj[u])
    if (!b[v] or match(b[v])) return b[v] = u;
  return 0;
}

bool test(int md) {
  for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = 0, b[i] = 0;
  x = 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (md >= dist2(i, j))
        adj[i].push_back(j);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    x++;
    ans += match(i);
  }

  return ans == n;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &s[i].st, &s[i].nd);
  for (int i = 1; i <= n; i++) scanf("%d%d", &t[i].st, &t[i].nd);

  int lo = 0, hi = 2*INF;
  while (lo < hi) {
    int md = (lo+hi)/2;

    if (test(md)) hi = md;
    else lo = md+1;
  }

  printf("%d\n", lo);
  return 0;
}
