#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = n-1; i >= 0; i--)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define REP1(i, n) for(int i = n; i > 0; i--)
#define fi first
#define se second
#define pb push_back
#define INF 0x3f3f3f3f
#define MAXN 200009
#define MAXLOGN 22
#define MOD 1000000007
#define EPS 1e-9
#define mset(x, y) memset(&x, y, sizeof x)
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
typedef long long ll;

#define db(x) cerr<<#x<<" == "<<x<<endl
#define _ <<", "<<

int par[200200];
map<int, int> mm[200200];

struct Edge {
  long long u, v, c;
  bool operator<(Edge o) const {
    if(c != o.c) return c < o.c;
    if(u == 0 || v == 0) return o.u != 0 && o.v != 0;
    return false;
  }
};

std::vector<Edge> edges;

int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }

int main() {
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  if (k == n) {
    std::cout << "-1\n";
    return 0;
  }
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    u--;v--;

    mm[u][v]++;
    mm[v][u]++;

    Edge e;
    e.u = u, e.v = v, e.c = c;
    if (u == 0 or v == 0) cnt++;
    edges.push_back(e);
  }

  for (int u = 0; u < n; u++) for (auto x : mm[u]) assert(x.second == 1);

  if (cnt < k) {
    std::cout << "-1\n";
    return 0;
  }

  long long ans = 0;
  auto test = [&](ll x) {
    auto ed = edges;
    for(auto &e : ed) {
      if(e.u == 0 || e.v == 0) {
        e.c -= x;
      }
    }

    std::sort(ed.begin(), ed.end());

    for(int i = 0; i < n; i++) {
      par[i] = i;
    }
    ans = 0;
    ll got = 0;

    for(auto e : ed) {
      if(getPar(e.u) != getPar(e.v)) {
        if(e.u == 0 || e.v == 0) {
          ans += x;
          got++;
        }
        ans += e.c;
        par[getPar(e.u)] = par[getPar(e.v)];
      }
    }
    //ans += (long long) got * x;
    return got;
  };
  long long l = -2e13, r = 2e13;
  if (test(l) > k or test(r) < k) {
    std::cout << "-1\n";
    return 0;
  }

  while(l < r) {
    ll mid = l + (r - l) / 2;

    if(test(mid) < k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  auto build = [&](ll x) {
    auto ed = edges;
    for(auto &e : ed) {
      if(e.u == 0 || e.v == 0) {
        e.c -= x;
      }
    }

    std::sort(ed.begin(), ed.end());

    for(int i = 0; i < n; i++) {
      par[i] = i;
    }
    ans = 0;
    ll got = 0;

    for(auto e : ed) {
      if(getPar(e.u) != getPar(e.v)) {
        if(e.u == 0 || e.v == 0) {
          if (got >= k) continue;
          ans += x;
          got++;
        }
        ans += e.c;
        par[getPar(e.u)] = par[getPar(e.v)];
      }
    }
    //ans += (long long) got * x;
    return got;
  };

  for (int i = 1; i < n; i++) {
    if (getPar(i) != getPar(0)) {
      std::cout << "-1\n";
      return 0;
    }
  }

  ll got = build(l);
  std::cout << 2 * (ans-(got-k)*l) << '\n';
}
