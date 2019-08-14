// @subject: inversion count
// @diff: easy

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
const int N = 1e5+5;

int x, y, h[2];
pii p[N];
int bit[N];

void add(int p) { for (p+=2; p < N; p+=p&-p) bit[p]++; }
int get(int p) {
  int r = 0;
  for (p+=2; p; p-=p&-p) r += bit[p];
  return r;
}

int main() {
  scanf("%d%d%d%d", &x, &y, &h[0], &h[1]);
  ll ans = 1ll*(h[0]+1)*(h[1]+1);

  for (int j = 0; j < 2; j++) {
    vector<int> c;
    for (int i = 0; i < h[j]; i++) {
      scanf("%d%d", &p[i].st, &p[i].nd);
      c.push_back(p[i].nd);
    }
    sort(p, p+h[j]);

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    memset(bit, 0, sizeof bit);

    for (int i = 0; i < h[j]; i++) {
      ll y = lower_bound(c.begin(), c.end(), p[i].nd) - c.begin();
      ans += i-get(y-1);
      add(y);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
