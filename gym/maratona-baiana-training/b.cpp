#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 100009
#define MAXM 1000009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x));
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
#define MAXS 2009

set<ii> st[MAXM];
int n, m;

class SegmentTree {
  void flip(int p, int l, int r, int a, int b, ii v, bool erase) {
    if (a > r || b < l) return;
    if (a <= l && r <= b) {
      if (erase) st[p].erase(v);
      else st[p].insert(v);
      return;
    }
    int m = (l+r) / 2;
    flip(2*p, l, m, a, b, v, erase);
    flip(2*p+1, m+1, r, a, b, v, erase);
  }
  void get(vector<ii> & ans, int p, int l, int r, int i) {
    for(ii pp : st[p]) ans.pb(pp);
    if (l == r) return;
    int m = (l+r) / 2;
    if (i <= m) get(ans, 2*p, l, m, i);
    else get(ans, 2*p+1, m+1, r, i);
  }
public:
  void insert(int a, int b, ii v) {
    if (a > b) swap(a, b);
    flip(1, 0, n-1, a, b, v, false);
  }
  void erase(int a, int b, ii v) {
    if (a > b) swap(a, b);
    flip(1, 0, n-1, a, b, v, true);
  }
  vector<ii> get(int i) {
    vector<ii> ans;
    get(ans, 1, 0, n-1, i);
    return ans;
  }
};

set<int> g[MAXN];
SegmentTree segt;
int mi[MAXN], ma[MAXN];

void add_edge(int u, int v) {
  g[u].insert(v);
  segt.insert(u, v, ii(u, v));
}

int main() {
  scanf("%d %d", &n, &m);
  FOR(u, n) {
    mi[u] = -1;
    ma[u] = INF;
  }
  FOR(j, m) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    if (u < v) {
      ma[u] = min(ma[u], v);
    }
    else {
      mi[u] = max(mi[u], v);
    }
  }
  FOR(u, n) {
    if (mi[u] > -1) {
      add_edge(u, mi[u]);
    }
    if (ma[u] < INF) {
      add_edge(u, ma[u]);
    }
  }
  queue<int> q;
  FOR(u, n) {
    if (g[u].empty()) q.push(u);
  }
  while(!q.empty()) {
    int w = q.front();
    q.pop();
    vector<ii> over = segt.get(w);
    for(ii pp : over) {
      int u = pp.fi;
      int v = pp.se;
      segt.erase(u, v, pp);
      if (!g[u].count(v)) continue;
      g[u].erase(v);
      if (g[u].empty()) {
        q.push(u);
      }
    }
  }
  int last = -1;
  int ans = 0, s = -1, t = -1;
  FOR(u, n) {
    if (g[u].empty()) {
      last = u;
    }
    else if (ans < u - last) {
      ans = u - last;
      s = last+1;
      t = u;
    }
  }
  if (ans == 0) printf("-1\n");
  else {
    printf("%d %d\n", s+1, t+1);
  }
  return 0;
}