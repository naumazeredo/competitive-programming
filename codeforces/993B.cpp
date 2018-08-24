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
const int N = 25;

int n, m;
pii a[N], b[N];

int get(pii x, pii y) {
  if (x.st == y.st) return x.st;
  if (x.st == y.nd) return x.st;
  if (x.nd == y.st) return x.nd;
  if (x.nd == y.nd) return x.nd;
  return 0;
}

int eq(pii x, pii y) {
  if (x.st > x.nd) swap(x.st, x.nd);
  if (y.st > y.nd) swap(y.st, y.nd);
  return x == y;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].st, &a[i].nd);
  for (int i = 0; i < m; i++) scanf("%d%d", &b[i].st, &b[i].nd);

  set<int> ans;

  for (int i = 0; i < n; i++) {
    int p = 0;
    for (int j = 0; j < m; j++) {
      if (eq(a[i], b[j])) continue;

      int v = get(a[i], b[j]);
      if (v) {
        if (!p) p = v;
        if (p != v) return !printf("-1\n");
      }
    }

    if (p) ans.insert(p);
  }

  for (int i = 0; i < m; i++) {
    int p = 0;
    for (int j = 0; j < n; j++) {
      if (eq(b[i], a[j])) continue;

      int v = get(b[i], a[j]);
      if (v) {
        if (!p) p = v;
        if (p != v) return !printf("-1\n");
      }
    }

    if (p) ans.insert(p);
  }

  assert(ans.size() > 0);
  if (ans.size() > 1) printf("0\n");
  else printf("%d\n", *ans.begin());

  return 0;
}
