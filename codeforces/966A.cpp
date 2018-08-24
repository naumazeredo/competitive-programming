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

int n, m, cl, ce, v, x, y, a, b;
int l, e;
int q;
set<int> sl, se;

int go1(int x, int y, int a, int b) {
  int dx = abs(x-a);

  if (dx == 0) return abs(y-b);

  int res = INF;

  auto it = sl.lower_bound(y);
  if (it != sl.begin()) it--;
  for (int i = 0; i < 3 and it != sl.end(); i++, it++) {
    int p = *it;
    res = min(res, abs(y-p)+abs(p-b)+abs(x-a));
  }

  return res;
}

int go2(int x, int y, int a, int b) {
  int dx = abs(x-a);

  int res = go1(x, y, a, b);

  auto it = se.lower_bound(y);
  if (it != se.begin()) it--;

  for (int i = 0; i < 3 and it != se.end(); i++, it++) {
    int p = *it;

    res = min(res, dx/v + !!(dx%v) + abs(y-p)+abs(p-b));

    for (int j = 0; j < 2; j++)
      res = min(res, abs(y-p) + (dx/v+j) + go1((dx/v + j)*v, p, dx, b));
  }

  return res;
}

int main() {
  scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
  for (int i = 0; i < cl; i++) scanf("%d", &l), sl.insert(l);
  for (int i = 0; i < ce; i++) scanf("%d", &e), se.insert(e);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d%d", &x, &y, &a, &b);
    printf("%d\n", go2(x,y,a,b));
  }

  return 0;
}
