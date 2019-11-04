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
const int N = 105;

int n, m, s[N], h[N], a[N], b[N], p[N], mrk[N];
vector<int> ans;

int test(int x) {
  ans.clear();
  for (int i = 1; i <= n; i++) b[i] = a[i];
  for (int i = 1; i <= m; i++) mrk[i] = 0;

  for (int i = x; i <= n; i++) if (p[i]) {
    int ch = h[p[i]];

    int ok = 1;
    for (int j = i-1; j >= x and ok; j--) {
      ch += b[j];
      if (ch < 0) ok = 0;
    }

    if (ok) {
      ans.push_back(p[i]);
      mrk[p[i]] = 1;
      for (int j = i-1; j >= x; j--) {
        b[j] = 0;
        if (p[j] and !mrk[p[j]]) mrk[p[j]] = 1, ans.push_back(p[j]);
      }
    }
  }

  for (int i = x-1; i >= 1; i--) if (p[i]) {
    int ch = h[p[i]];

    int ok = 1;
    for (int j = i+1; j <= x and ok; j++) {
      ch += b[j];
      if (ch < 0) ok = 0;
    }

    if (ok) {
      ans.push_back(p[i]);
      mrk[p[i]] = 1;
      for (int j = i+1; j <= x; j++) {
        b[j] = 0;
        if (p[j] and !mrk[p[j]]) mrk[p[j]] = 1, ans.push_back(p[j]);
      }
    }
  }

  for (int i = 1; i <= m; i++) if (!mrk[i]) return 0;
  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &s[i], &h[i]), p[s[i]] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  for (int i = 1; i <= n; i++) if (test(i)) {
    printf("%d\n", i);
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
  }

  printf("-1\n");

  return 0;
}
