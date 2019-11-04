// @subject: xor-3-sat, gauss elimination
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
const int N = 4e3+5;

int m, n;
bitset<2005> b[N];
int r[N];
int ans[N];

void scan(int k) {
  scanf(" (");

  r[k] = 1;
  for (int x, i = 0; i < 3; i++) {
    if (scanf("x%d", &x) == 1) b[k].flip(x);
    else if (scanf("not x%d", &x) == 1) b[k].flip(x), r[k] ^= 1;
    scanf(" or ");
  }

  scanf(")");
  scanf(" and ");
}

string solve() {
  for (int i = 1; i <= n; i++) {
    int p = 0;
    for (int j = i; j <= m and !p; j++) if (b[j][i]) p = j;
    if (!p) {
      m++;
      swap(b[i], b[m]);
      swap(r[i], r[m]);
      continue;
    }

    swap(b[i], b[p]);
    swap(r[i], r[p]);

    for (int j = i+1; j <= m; j++) if (b[j][i]) b[j] ^= b[i], r[j] ^= r[i];
  }

  for (int i = n; i >= 1; i--) {
    if (!b[i][i]) continue;
    for (int j = i-1; j >= 1; j--) if (b[j][i]) b[j] ^= b[i], r[j] ^= r[i];
  }

  for (int i = 1; i <= m; i++) if (b[i].count() == 0 and r[i]) return "impossible";

  memset(ans, -1, sizeof ans);
  for (int i = 1; i <= n; i++) {
    if (!b[i][i]) { ans[i] = 1; continue; }

    if (b[i].count() == 1) {
      ans[i] = r[i];
      b[i].reset(i);
      r[i] = 0;
      continue;
    }

    ans[i] = 1;
    b[i].reset(i);
    r[i] ^= ans[i];

    int j;
    for (j = i+1; !b[i][j]; j++) ;
    swap(b[i], b[j]);
    swap(r[i], r[j]);

    for (int k = j-1; k >= 1; k--) if (b[k][j]) b[k] ^= b[j], r[k] ^= r[j];
  }

  string res = "";
  for (int i = 1; i <= n; i++) res += (ans[i] != 0) ? 'T' : 'F';
  return res;
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) scan(i);
  printf("%s\n", solve().c_str());

  return 0;
}
