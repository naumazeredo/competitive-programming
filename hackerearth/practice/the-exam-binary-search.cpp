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

int t;
ll x, l, n;

int solv(ll m) {
  //db(m _ log((ld)m)/log(2) _ log((ld)l)/log(2));
  return log((ld)m)/log(2) + (n-1) <= log((ld)l)/log(2);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld", &x, &l, &n);
    if (n == 0) { printf("0\n"); continue; }
    if (n > 63) { printf("%lld\n", x); continue; }

    int ans = 0;
    if (x > l) ans = x-l, x=l;

    ll lo = 1, hi = x+1;
    while (lo < hi) {
      ll mid = (lo+hi)/2;
      //db(lo _ mid _ hi);
      if (solv(mid)) lo = mid+1;
      else hi = mid;
    }
    lo--;
    //if (!solv(lo)) lo--;
    printf("%lld\n", ans+x-lo);
  }
  return 0;
}
