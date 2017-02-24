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

int n, m, k;

ll solve(ll x) {
  ll ans = x*x;
  if (k < x) ans -= (x-k)*(x-k-1)/2;
  if (n-1-k < x) ans -= (x-n+1+k)*(x-n+k)/2;
  return ans;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  k--;
  m -= n;

  int lo = 0, hi = m;
  while (lo < hi) {
    int mid = (lo+hi+1)/2;
    ll t = solve(mid);
    if (t > m) hi = mid-1;
    else lo = mid;
  }

  printf("%d\n", lo+1);

  return 0;
}
