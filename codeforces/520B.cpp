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

int n, m;
int res;
int vis[22222];

int main() {
  scanf("%d%d", &n, &m);

  queue<int> x, s;
  x.push(n), s.push(0);

  while (!x.empty()) {
    int u = x.front(); x.pop();
    int d = s.front(); s.pop();

    if (u == m) { res = d; break; }
    if (u < m and !vis[2*u]) vis[2*u]=1, x.push(2*u), s.push(d+1);
    if (u > 0 and !vis[u-1]) vis[u-1]=1, x.push(u-1), s.push(d+1);
  }

  printf("%d\n", res);

  return 0;
}
