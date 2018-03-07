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
  #define db(x)
  #define dbs(x)
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

int n, x, p[N], a[N], m[N], v[N];
int bit[N];
map<int, int> st[4*N];

void build(int p, int l, int r) {
  if (l == r) { st[p][m[l]]++; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);

  for (auto k : st[2*p]) st[p][k.st] += k.nd;
  for (auto k : st[2*p+1]) st[p][k.st] += k.nd;
}

int query(int p, int l, int r, int i, int j, int x) {
  if (l > j or r < i) return 0;
  if (i <= l and r <= j) return st[p][x];

  return query(2*p, l, (l+r)/2, i, j, x) + query(2*p+1, (l+r)/2+1, r, i, j, x);
}

void add(int p) { for (p+=2; p<N; p+=p&-p) bit[p]++; }
int query(int p) {
  int res = 0;
  for (p+=2; p; p-=p&-p) res+=bit[p];
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x), p[x] = i, a[i] = x;

  map<int, int> mm;
  mm[INF] = 0;

  for (int i = 1; i <= n; i++) {
    m[i] = mm.lower_bound(a[i])->nd;
    mm[a[i]] = i;
  }

  for (int i = n; i > 0; i--) {
    int q = query(p[i]);
    add(p[i]);
    if (q > 1) m[p[i]] = -1;
  }

  build(1, 1, n);

  int ans = n;
  v[n] = query(1, 1, n, p[n], n, p[n])-1;
  //db(v[n]);
  for (int i = n-1; i > 0; i--) {
    if (m[p[i]]) v[i] = 0;
    else v[i] = query(1, 1, n, p[i], n, p[i]) - 1;
    //v[i] += query(1, 1, n, 1, n, 0);
    //db(i _ v[i]);

    if (v[i] >= v[ans]) ans = i;
  }
  printf("%d\n", ans);

  return 0;
}
