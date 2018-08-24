// @subject: 
// @diff: 

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

int n, m, k, s;
int a[N];
vector<ll> t[N];
int dist[N];
vector<int> adj[N];

void bfs(int x) {
  for (int i = 1; i <= n; i++) dist[i] = INF;

  queue<int> q;
  for (int i = 1; i <= n; i++) if (a[i] == x) {
    q.push(i);
    dist[i] = 0;
  }

  while (q.size()) {
    int u = q.front(); q.pop();
    t[u].push_back(dist[u]);

    for (int v : adj[u]) if (dist[v] > dist[u] + 1) {
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
}

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int u, v, i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= k; i++) bfs(i);

  for (int i = 1; i <= n; i++) {
    sort(t[i].begin(), t[i].end());
    ll ans = 0;
    for (int j = 0; j < s; j++) ans += t[i][j];
    printf("%lld ", ans);
  }
  printf("\n");

  return 0;
}
