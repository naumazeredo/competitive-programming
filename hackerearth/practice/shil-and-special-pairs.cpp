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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int n, m, d, l, r;
int v[N], p[N];
int ql[N], qr[N], qp[N];
int bit[N];
int ans[N];

bool func(int a, int b) { return qr[a] < qr[b]; }

void add(int u) { while (u<=n) bit[u]++, u+=u&-u; }
int query(int u) {
  int s = 0;
  while (u) s+=bit[u], u-=u&-u;
  return s;
}

int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]), p[v[i]]=i;
  for (int i = 0; i < m; ++i) scanf("%d%d", &ql[i], &qr[i]), qp[i]=i;
  sort(qp, qp+m, func);

  int q = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = max(1,v[i]-d); j <= min(n,v[i]+d); ++j) if (p[j]<=i) add(p[j]);
    while (q<m and qr[qp[q]] <= i) ans[qp[q]] = query(qr[qp[q]])-query(ql[qp[q]]-1), q++;
  }

  for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
  return 0;
}
