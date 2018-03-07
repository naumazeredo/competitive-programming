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

int n, s, l, a[N];
int f[N];
int st[4*N];

void build(int p, int l, int r) {
  if (l == r) { st[p] = INF; return; }
  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);
  st[p] = INF;
}

void add(int p, int l, int r, int i, int v) {
  if (l > i or r < i) return;
  if (l == r) { st[p] = v; return; }
  int m = (l+r)/2;
  add(2*p, l, m, i, v);
  add(2*p+1, m+1, r, i, v);
  st[p] = min(st[2*p],st[2*p+1]);
}

int query(int p, int l, int r, int i, int j) {
  if (r < i or l > j) return INF;
  if (i <= l and r <= j) return st[p];

  int m = (l+r)/2;
  return min(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
}

void go(int p) {
  if (f[p] - p + 1 < l) return;
  if (f[p] == n-1) {
    add(1, 0, n-1, p, 1);
    return;
  }

  int ans = query(1, 0, n-1, p+l, f[p]+1) + 1;
  ans = min(INF, ans);
  add(1, 0, n-1, p, ans);
}

int main() {
  scanf("%d%d%d", &n, &s, &l);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  multiset<int> m;
  int i = 0, j = -1;
  while (j < n) {
    while (j < n and (m.empty() or *m.rbegin() - *m.begin() <= s)) {
      j++;
      m.insert(a[j]);
    }

    while (m.size() and *m.rbegin() - *m.begin() > s) {
      f[i] = j-1;
      m.erase(m.find(a[i]));
      i++;
    }
  }

  for (; i < n; i++) f[i] = n-1;

  //for (int i = 0; i < n; i++) db(i _ f[i]);

  build(1, 0, n-1);
  for (int i = n-1; i >= 0; i--) go(i);

  /*
  for (int i = 0; i < n; i++)
    db(i _ query(1, 0, n-1, i, i));
    */

  int ans = query(1, 0, n-1, 0, 0);
  printf("%d\n", ans==INF ? -1 : ans);

  return 0;
}
