// template
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
const int N = 1e2+5;

int n, a, b;
char c;
vi adj[N];

// Articulation points and Bridges O(V+E)
int par[N], art[N], low[N], num[N], cnt, ch[N];

void articulation(int u) {
  low[u] = num[u] = ++cnt;
  for (int v : adj[u]) {
    if (!num[v]) {
      par[v] = u;
      ch[u]++;
      articulation(v);
      if (low[v] >= num[u]) art[u] = 1;
      //if (low[v] >  num[u]) // u-v bridge
      low[u] = min(low[u], low[v]);
    } else if (v != par[u]) low[u] = min(low[u], num[v]);
  }
}


int main() {
  while (~scanf("%d", &n) and n) {
    cnt = 0;
    for (int i = 1; i <= n; ++i)
      adj[i].clear();
    cl(art,0); cl(num,0); cl(low,0); cl(ch,0);

    while (scanf("%d", &a) and a) {
      while (scanf("%c", &c) and c!='\n') {
        scanf("%d", &b);
        adj[a].pb(b); adj[b].pb(a);
      }
    }

    articulation(1);
    art[1]=ch[1]>1;

    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += art[i];
    printf("%d\n", ans);
  }

  return 0;
}
