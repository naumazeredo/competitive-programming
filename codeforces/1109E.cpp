// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
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

int n, m, a[N], q;
int vm[10];

int add(int a, int b) {
  a += b;
  if (a >= m) a-=m;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a+=m;
  return a;
}

int mul(int a, int b) {
  return 1ll*a*b%m;
}

int fexp(int a, int b) {
  int r = 1;
  for (a%=m; b; b>>=1, a=mul(a,a)) if (b&1) r=mul(r,a);
  return r;
}

int inv(int a) { return fexp(a, m-2); }

int seg[4*N];
int hl[4*N], lz[4*N][10], lzv[4*N];

void build(int p = 1, int l = 1, int r = n) {
  lzv[p] = 1;
  hl[p] = 0;

  if (l == r) { lzv[p] = a[l]%m; return; }
  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);
  seg[p] = add(seg[2*p], seg[2*p+1]);
}

void push(int p, int l, int r) {
  if (hl[p]) {
    if (l != r) {
      for (int i = 0; i < 10; i++) lz[2*p][i] += lz[p][i];
      for (int i = 0; i < 10; i++) lz[2*p+1][i] += lz[p][i];
      lzv[2*p] = mul(lzv[2*p], lzv[p]);
      lzv[2*p+1] = mul(lzv[2*p+1], lzv[p]);
      hl[2*p] = hl[2*p+1] = 1;
    }

    seg[p] = mul(seg[p], lzv[p]);
    for (int i = 0; i < 10 and vm[i]; i++) seg[p] = mul(seg[p], fexp(vm[i], lz[p][i]));

    if (l != r) {
      for (int i = 0; i < 10; i++) lz[p][i] = 0;
      lzv[p] = 1;
    }
    hl[p] = 0;
  }
}

void update_1(int i, int j, int x, int p = 1, int l = 1, int r = n) {
  push(p, l, r);
  if (i > r or j < l) return;
  if (i <= l and r <= j) {
    for (int i = 0; i < 10 and vm[i]; i++)
      while (x%vm[i] == 0)
        lz[p][i]++, x /= vm[i];
    lzv[p] = mul(lzv[p], x);
    hl[p] = 1;
    push(p, l, r);
    return;
  }

  int m = (l+r)/2;
  update_1(i, j, x, 2*p, l, m);
  update_1(i, j, x, 2*p+1, m+1, r);
  seg[p] = add(seg[2*p], seg[2*p+1]);
}

void update_2(int i, int x, int p = 1, int l = 1, int r = n) {
  push(p, l, r);
  if (l > i or r < i) return;
  if (l == r and l == i) {
    for (int i = 0; i < 10 and vm[i]; i++)
      while (x%vm[i] == 0)
        lz[p][i]--, x /= vm[i];
    lzv[p] = mul(lzv[p], inv(x));

    seg[p] = lzv[p];
    for (int i = 0; i < 10 and vm[i]; i++) seg[p] = mul(seg[p], fexp(vm[i], lz[p][i]));
  }
  int m = (l+r)/2;
  update_2(i, x, 2*p, l, m);
  update_2(i, x, 2*p+1, m+1, r);
  seg[p] = add(seg[2*p], seg[2*p+1]);
}

int query(int i, int j, int p = 1, int l = 1, int r = n) {
  if (i > r or l > j) return 0;
  if (i <= l and r <= j) return seg[p];
  int m = (l+r)/2;
  return add(query(i, j, 2*p, l, m), query(i, j, 2*p+1, m+1, r));
}


int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  {
    int l = 0;
    int x = m;
    for (int i = 2; i*i <= x; i++) if (x%i == 0) {
      vm[l++] = i;
      while (x%i == 0) x /= i;
    }
    if (x > 1) vm[l++] = x;
  }

  build();

  scanf("%d", &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      update_1(l, r, x);
    }
    if (t == 2) {
      int p, x;
      scanf("%d%d", &p, &x);
      update_2(p, x);
    }
    if (t == 3) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", query(l, r));
    }
  }
  return 0;
}
