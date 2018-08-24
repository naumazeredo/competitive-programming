// @subject: 
// @diff: 

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
const int N = 2e5+5;

struct Bit {
  vector<ll> bit;

  void init(int n) { bit.resize(n+5); }
  void add(int p, int v) {
    for (p+=2; p < (int)bit.size(); p+=p&-p) bit[p]+=v;
  }

  ll query(int p) {
    ll res = 0;
    for (p+=2; p; p-=p&-p) res += bit[p];
    return res;
  }
};

int n, q, a[N], p, x;
Bit bit;

int get(ll v) {
  if (bit.query(n) < v) return INF;

  int p = 0;
  for (int i = 20; i >= 0; i--)
    if ((p|(1<<i)) <= n and bit.query(p|(1<<i)) < v)
      p |= (1<<i);
  return p+1;
}

void query() {
  bit.add(p, x-a[p]);
  a[p] = x;

  p = 1;
  while (1) {
    if (a[p] == bit.query(p-1)) {
      printf("%d\n", p);
      return;
    }

    p = get(2*bit.query(p));
    if (p == INF) {
      printf("-1\n");
      return;
    }
  }

  printf("-1\n");
}

int main() {
  scanf("%d%d", &n, &q);
  bit.init(n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), bit.add(i, a[i]);

  for (int i = 0; i < q; i++) {
    scanf("%d%d", &p, &x);
    query();
  }

  return 0;
}
