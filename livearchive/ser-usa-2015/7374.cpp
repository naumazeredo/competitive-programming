/*
  Using SEGTREE
  Better solution: LIS nlogn
*/

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

int n, r, w, h, x[N], y[N], o[N], dp[N];
int st[4*N];

void update(int p, int l, int r, int x, int v) {
  if (l > x or r < x) return;
  if (l == r and l == x) { st[p] = v; return; }
  update(2*p, l, (l+r)/2, x, v);
  update(2*p+1, (l+r)/2+1, r, x, v);
  st[p] = max(st[2*p], st[2*p+1]);
}

int query(int p, int l, int r, int i, int j) {
  if (l > j or r < i) return 0;
  if (l >= i and r <= j) return st[p];

  //db(max(query(2*p, l, (l+r)/2, i, j), query(2*p+1, (l+r)/2+1, r, i, j)));
  return max(query(2*p, l, (l+r)/2, i, j), query(2*p+1, (l+r)/2+1, r, i, j));
}

ll calc(int i, ll a, ll b) { return a*x[i] + b*y[i]; }

int main() {
  while (~scanf("%d%d%d%d", &n, &r, &w, &h)) {
    cl(st,0);

    for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]), o[i] = i;
    sort(o, o+n, [](int a, int b) { return calc(a, r, 1) == calc(b, r, 1) ? calc(a, -r, 1) < calc(b, -r, 1) : calc(a, r, 1) < calc(b, r, 1); });

    //for (int i = 0; i < n; i++) db(i _ o[i] _ calc(o[i], r, 1) _ calc(o[i], -r, 1));

    vector<ll> v;
    for (int i = 0; i < n; i++) v.pb(calc(i, -r, 1));
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++) y[i] = lower_bound(v.begin(), v.end(), calc(i, -r, 1))-v.begin();

    for (int i = 0; i < n; i++) {
      int c = o[i];
      dp[c] = query(1, 0, n-1, 0, y[c])+1;
      update(1, 0, n-1, y[c], dp[c]);
    }
    printf("%d\n", st[1]);
  }
  return 0;
}
