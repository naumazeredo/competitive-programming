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
const int N = 1e5+5;

ll n;

int main() {
  while (~scanf("%lld", &n)) {
    if (n == 3) { printf("4\n"); continue; }
    if (n < 7) { printf("No such base\n"); continue; }

    n-=3;
    ll ans = n;
    for (ll i = 1; i*i <= n; i++) if (n%i==0) {
      if (i > 3) ans = min(ans, i);
      if (n/i > 3) ans = min(ans, n/i);
    }

    printf("%lld\n", ans);
  }
  return 0;
}
