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
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

char s[N];
int n, l, p;

ll cont(int x) {
  set<ull> ss;
  for (int i = 0; i < x; i++) {
    ull h = 0;
    for (int j = i; j < x; j++) {
      h = h*MOD + s[j%p];
      ss.insert(h);
    }
  }
  return ss.size();
}

int main() {
  scanf("%s%d", s, &l);
  n = strlen(s);

  for (p = 1; p < n; p++) if (n%p == 0) {
    int ok = 1;
    for (int i = p; i < n; i++) if (s[i] != s[i-p]) { ok = 0; break; }
    if (ok) break;
  }

  ll ans = 0;
  if (l < 2*p) ans = cont(l);
  else ans = cont(2*p) + 1ll*(l-2*p)*p;
  printf("%lld\n", ans);

  return 0;
}
