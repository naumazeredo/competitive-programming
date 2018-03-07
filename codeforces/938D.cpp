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
const int N = 2e5+5;

int n, m, u, v, o[N];
ll w, a[N], ans[N];
vector<int> adj[N];
vector<ll> adjw[N];

void apply() {
  priority_queue<pll> pq;

  for (int i = 1; i <= n; i++) {
    pq.push({ 0, i });
    ans[i] = a[i];
  }

  while (pq.size()) {
    ll  k = -pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (ans[u] < k) continue;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      ll w = adjw[u][i];
      if (ans[v] > ans[u] + 2*w) {
        ans[v] = ans[u] + 2*w;
        pq.push({ -ans[v], v });
      }
    }
  }
}

int main() {
  cl(ans,63);

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%lld", &u, &v, &w);
    adj[u].push_back(v); adjw[u].push_back(w);
    adj[v].push_back(u); adjw[v].push_back(w);
  }
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

  apply();

  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");

  return 0;
}
