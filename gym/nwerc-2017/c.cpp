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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int p[N];
vector<ll> v;
ll a, b, k[N], r[N];

int main() {
  for (ll i = 2; i < N; i++) if (!p[i]) {
    for (ll j = i*i; j < N; j+=i) p[j] = 1;
    v.push_back(i);
  }

  scanf("%lld%lld", &a, &b);
  for (ll x = a; x <= b; x++) k[x-a] = x, r[x-a] = 1;

  for (ll p : v) {
    ll x = (a+p-1)/p*p;
    for (; x <= b; x += p) {
      ll val = 1;
      ll z = p;
      while (k[x-a] % p == 0) val += z, k[x-a] /= p, z *= p;
      r[x-a] *= val;
    }
  }

  ll ans = 0;
  for (ll i = a; i <= b; i++) {
    if (k[i-a] != 1) r[i-a] *= 1+k[i-a];
    ans += r[i-a];
  }

  printf("%lld\n", ans);

  return 0;
}
