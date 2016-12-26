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
const int N = 1e5+5;

const int dx[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
const int dy[] = { 1, 0, -1, -1, -1, 0, 1, 1 };

int n, r, a, b;
pii s, t;
map<pii, int> m;

int main() {
  scanf("%d%d", &s.st, &s.nd),
  scanf("%d%d", &t.st, &t.nd),

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &r, &a, &b);
    for (int j = a; j <= b; ++j)
      m[{ r, j }] = INF;
  }

  if (!m.count(s) or !m.count(t))
    return 0*printf("-1\n");

  queue<pii> q;
  q.push(s);
  m[s] = 0;

  while (q.size()) {
    auto u = q.front();
    q.pop();

    if (u == t) break;

    int d = m[u];
    for (int i = 0; i < 8; ++i) {
      pii v = { u.st+dx[i], u.nd+dy[i] };
      if (m.count(v) and m[v] > d+1)
        m[v] = d+1, q.push(v);
    }
  }

  printf("%d\n", m[t]<INF?m[t]:-1);

  return 0;
}
