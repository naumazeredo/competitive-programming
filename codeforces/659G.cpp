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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e6+5;

ll mod(ll x) { return x%MOD; }

int n;
ll ans, h[N], s[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &h[i]), h[i]--;
  for (int i = 2; i <= n; ++i) {
    s[i] = mod(mod(s[i-1]*min(min(h[i-2], h[i-1]), h[i]))+min(h[i-1], h[i]));
    ans = mod(ans+mod(min(h[i-1],h[i])*s[i]));
  }
  for (int i = 1; i <= n; ++i) ans = mod(ans+h[i]);
  printf("%lld\n", ans);
  return 0;
}
