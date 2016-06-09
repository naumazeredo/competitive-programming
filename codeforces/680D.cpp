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

ll m;
pll ans;

ll p3(ll x) { return x*x*x; }

void go(ll t, ll p, ll a) {
  if (t == 0) { ans = max(ans, mp(p,a)); return; }
  ll x = 1;
  while (p3(x+1)<=t) ++x;

  go(t-p3(x), p+1, a+p3(x));
  go(p3(x)-1-p3(x-1), p+1, a+p3(x-1));
}

int main() {
  scanf("%lld", &m);
  go(m, 0, 0);
  printf("%lld %lld\n", ans.st, ans.nd);

  return 0;
}
