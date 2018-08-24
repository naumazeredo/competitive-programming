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

const int N = 2e5+5;

int n, a[N];
ll ans;
map<int, vector<int>> m;

int st[4*N];

void add(int p, int l, int r, int i) {
  if (l > i or r < i) return;
  if (l == r and l == i) { st[p]++; return; }
  int m = (l+r)/2;
  add(2*p, l, m, i);
  add(2*p+1, m+1, r, i);
  st[p] = st[2*p]+st[2*p+1];
}

int query(int p, int l, int r, int i, int j) {
  if (l > j or r < i) return 0;
  if (i <= l and r <= j) return st[p];
  int m = (l+r)/2;
  return query(2*p, l, m, i, j) + query(2*p+1, m+1, r, i, j);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), m[a[i]].push_back(i);

  int p = 0;
  for (auto& x : m) {
    int v = x.first;

    for (; p <= n and p <= v; p++) if (a[p] > p)
      ans += min(a[p], n) - p - query(1, 1, n, p, min(a[p], n));

    for (auto& y : x.second)
      add(1, 1, n, y);
  }

  printf("%lld\n", ans);

  return 0;
}
