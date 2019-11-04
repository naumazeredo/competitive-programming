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
const int N = 2e5+5;

int t, n, m, k, c[30], cnt[30];
char s[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%s", &n, &m, &k, s);
    memset(c, 0, sizeof c);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; s[i]; i++) c[(int)s[i]-'A']++;

    set<pii> ss;
    for (int i = 0; i < 30; i++) if (c[i]) ss.insert({ c[i], i });

    pii sz { n, m };
    while (sz.st != 0 and sz.nd != 0) {
      pii v = *ss.rbegin(); ss.erase(*ss.rbegin());
      if (v.st <= sz.st and v.st <= sz.nd) {
        cnt[v.nd] = v.st;
        c[v.nd] = 0;
        if (sz.st < sz.nd) sz.st -= v.st;
        else sz.nd -= v.st;
      } else if (v.st <= sz.st) {
        cnt[v.nd] = v.st;
        c[v.nd] = 0;
        sz.st -= v.st;
      } else if (v.st <= sz.nd) {
        cnt[v.nd] = v.st;
        c[v.nd] = 0;
        sz.nd -= v.st;
      } else {
        if (sz.st > sz.nd) {
          cnt[v.nd] = sz.st;
          c[v.nd] -= sz.st;
          sz.st = 0;
        } else {
          cnt[v.nd] = sz.nd;
          c[v.nd] -= sz.nd;
          sz.nd = 0;
        }
      }
    }

    ss.clear();
    for (int i = 0; i < 30; i++) if (c[i]) ss.insert({ cnt[i], i });

    ll ans = 0;
    ll left = max(sz.st, sz.nd);
    while (left) {
      pii v = *ss.begin();

      ans += v.st;

      c[v.nd]--;
      left--;

      if (!c[v.nd]) ss.erase(ss.begin());
    }

    printf("%lld\n", ans);
  }
  return 0;
}
