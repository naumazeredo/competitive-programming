// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 2e5+5;

int n, a[N];
map<int, int> mi, ma;

int fexp(ll a, ll b) {
  ll r = 1;
  for (a%=MOD; b; b>>=1, a=(a*a)%MOD) if (b&1) r=(r*a)%MOD;
  return r;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (mi.count(a[i])) {
      mi[a[i]] = min(mi[a[i]], i);
      ma[a[i]] = max(ma[a[i]], i);
    } else {
      mi[a[i]] = i;
      ma[a[i]] = i;
    }
  }

  int cnt = 0;
  int i = 0;
  while (i < n) {
    cnt++;
    int last = ma[a[i]];
    while (i < last) {
      i++;
      last = max(last, ma[a[i]]);
    }
    i++;
  }

  printf("%d\n", fexp(2, cnt-1));

  return 0;
}
