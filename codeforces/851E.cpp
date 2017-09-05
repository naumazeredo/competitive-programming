#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

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
const int N = 1e2+5, P = 1e6+5;

int n, a[N], p[P];
vi primes;
map<ll, ll> m, g;

int go(ll k) {
  if (g.count(k)) return g[k];

  int v[100] = {};
  for (int i = 1; i <= 32; i++) {
    int x = (((1<<i)-1)&k) | (k>>i);
    if (x == k) break;
    v[go(x)]=1;
  }

  for (int i = 0; i < 100; i++) if (!v[i]) return g[k] = i;
  return g[k] = 100;
}

int main() {
  for (ll i = 2; i < P; i++) if (!p[i]) {
    primes.pb(i);
    for (ll j = i*2; j < N; j+=i) p[j]=1;
  }

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);

    for (int p : primes) if (a[i]%p==0) {
      int k = 0;
      while (a[i]%p == 0) k++, a[i]/=p;
      m[p] |= (1ll<<k);
    }
    if (a[i] != 1) m[a[i]] |= (1ll<<1);
  }

  g[1] = 0;
  int ans = 0;
  for (auto p : m) ans ^= go(p.nd);

  printf("%s\n", ans?"Mojtaba":"Arpa");

  return 0;
}
