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
const int N = 4e5+5;

int n, t;
vector<int> v[4];

int main() {
  scanf("%d", &n);
  for (int x, y, a, i = 0; i < n; i++) {
    scanf("%1d%1d%d", &x, &y, &a);
    v[2*x+y].push_back(a);
  }

  for (int i = 0; i < 4; i++) sort(v[i].begin(), v[i].end());

  t = v[3].size();

  int ans = 0;
  for (int x : v[3]) ans += x;

  while (v[1].size() and v[2].size()) {
    ans += v[1].back(); v[1].pop_back();
    ans += v[2].back(); v[2].pop_back();
  }

  while (v[1].size()) v[0].push_back(v[1].back()), v[1].pop_back();
  while (v[2].size()) v[0].push_back(v[2].back()), v[2].pop_back();
  sort(v[0].begin(), v[0].end());

  for (int i = 0; i < t and v[0].size(); i++)
    ans += v[0].back(), v[0].pop_back();

  printf("%d\n", ans);

  return 0;
}
