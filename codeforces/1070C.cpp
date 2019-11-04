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
const int M = 2e5+5, N = 1e6+5;

int n, k, m;
int l[M], r[M], c[M], p[M];
vector<pii> events[N];

int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d%d", &l[i], &r[i], &c[i], &p[i]);
    events[l[i]].push_back({ i, +1 });
    events[r[i]+1].push_back({ i, -1 });
  }

  multiset<pii> s, v;
  int tot = 0;
  ll price = 0;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    //db(i);
    for (pii x : events[i]) {
      pii e = { p[x.st], c[x.st] };
      //db(x.st);

      if (x.nd == 1) {
        v.insert(e);
        tot += c[x.st];
        price += 1ll * c[x.st] * p[x.st];

        while (v.size() and tot - v.rbegin()->nd >= k) {
          tot -= v.rbegin()->nd;
          price -= 1ll * v.rbegin()->st * v.rbegin()->nd;

          s.insert(*v.rbegin());
          v.erase(v.find(*v.rbegin()));
        }
      } else {
        if (v.count(e)) {
          v.erase(v.find(e));
          tot -= c[x.st];
          price -= 1ll * c[x.st] * p[x.st];

          while (s.size() and tot < k) {
            tot += s.begin()->nd;
            price += 1ll * s.begin()->st * s.begin()->nd;

            v.insert(*s.begin());
            s.erase(s.find(*s.begin()));
          }
        } else {
          s.erase(s.find(e));
        }
      }
    }

    ans += price;
    if (v.size() and tot > k) ans -= 1ll * (tot - k) * v.rbegin()->st;
  }

  printf("%lld\n", ans);

  return 0;
}
