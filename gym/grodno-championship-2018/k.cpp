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
const int N = 1e5+5;

ll k;
ll f[20][20], l[20][20], s[20], p[20];
vector<int> ans;

bool bt(int t, int d, ll acc) {
  if (d == 0) return acc == 0;

  int i = 9;
  for (; i > 0 and i*f[t][d] > acc; i--) ;

  for (; i >= 0 and i*f[t][d] + l[t][d-1] >= acc; i--) {
    if (t == d and i == 0) break;
    ans.push_back(i);
    if (bt(t, d-1, acc - i*f[t][d])) return 1;
    ans.pop_back();
  }

  return 0;
}

int main() {
  p[0] = 1; s[0] = 1;
  for (int i = 1; i < 20; i++) {
    p[i] = 10 * p[i-1];
    s[i] = s[i-1] + p[i];
  }

  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= i; j++) {
      f[i][j] = s[j-1] + (i-j) * p[j-1];
      l[i][j] = l[i][j-1] + 9*f[i][j];
    }

  scanf("%lld", &k);
  for (int i = 1; i <= 15; i++) {
    if (bt(i, i, k)) {
      for (auto x : ans) printf("%d", x);
      printf("\n");
      return 0;
    }
  }

  printf("-1\n");

  return 0;
}
