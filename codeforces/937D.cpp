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

int n, m, s, c, x;

vector<int> adj[N], path;
int vis[N][2], draw, win;

void dfs(int u, int p) {
  if (vis[u][p] == 1) {
    draw = 1;
    return;
  }
  if (vis[u][p]) return;
  if (win) return;

  vis[u][p] = 1;
  path.push_back(u);

  if (adj[u].empty() and p == 1) {
    win = true;
  } else {
    for (int v : adj[u]) dfs(v, 1-p);
  }

  if (win) return;

  vis[u][p] = 2;
  path.pop_back();
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c);
    for (int j = 0; j < c; j++) {
      scanf("%d", &x);
      adj[i].push_back(x);
    }
  }
  scanf("%d", &s);

  dfs(s, 0);

  if (win) {
    printf("Win\n");
    for (int x : path) printf("%d ", x);
    printf("\n");
  } else if (draw) printf("Draw\n");
  else printf("Lose\n");

  return 0;
}
