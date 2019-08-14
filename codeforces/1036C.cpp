// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

int t;
ll l, r, p[20];
vector<ll> v;

int main() {
  p[0] = 1;
  for (int i = 1; i < 20; i++) p[i] = 10*p[i-1];

  for (int i = 0; i <= 18; i++) for (int j = i+1; j <= 18; j++) for (int k = j+1; k <= 18; k++)
    for (int vi = 0; vi <= 9; vi++) for (int vj = 0; vj <= 9; vj++) for (int vk = 0; vk <= 9; vk++) {
      ll x = vi*p[i]+vj*p[j]+vk*p[k];
      v.push_back(x);
    }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &l, &r);
    int ans = lower_bound(v.begin(), v.end(), r+1) - lower_bound(v.begin(), v.end(), l);
    printf("%d\n", ans);
  }

  return 0;
}
