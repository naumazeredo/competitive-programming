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
const int N = 1e2+5;

int n, t, s;
map<ll, ll> a, b;

int main() {
  while (~scanf("%d%d", &n, &t)) {
    a.clear();
    b.clear();
    for (int i = 0; i < n/2; ++i) {
      scanf("%d", &s);
      map<ll, ll> x;
      x[s] = 1;
      for (auto v : a) x[s+v.st] += v.nd;
      for (auto v : x) a[v.st] += v.nd;
    }

    for (int i = n/2; i < n; ++i) {
      scanf("%d", &s);
      map<ll, ll> x;
      x[s] = 1;
      for (auto v : b) x[s+v.st] += v.nd;
      for (auto v : x) b[v.st] += v.nd;
    }

    ll ans = 0;
    ans += a[t]; ans += b[t];
    for (auto v : a) ans += (v.nd * b[t-v.st]);
    printf("%lld\n", ans);
  }
  return 0;
}
