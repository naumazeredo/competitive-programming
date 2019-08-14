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
const int N = 1e7+5;

int n;

int ans[] = {
0,
0,
1,
1,
5,
1,
21,
1,
85,
73,
341,
89,
1365,
1,
5461,
4681,
21845,
1,
87381,
1,
349525,
299593,
1398101,
178481,
5592405,
1082401
};

int main() {
  /*
  for (int i = 0; i < 26; i++) {
    int a = (1<<i)-1;
    for (int b = 1; b < a; b++)
      ans[i] = max(ans[i], __gcd(a^b, a&b));
    db(i _ a _ ans[i]);
  }
  */

  scanf("%d", &n);
  for (int a, i = 0; i < n; i++) {
    scanf("%d", &a);

    int ok = 0;
    for (int i = 0; i < 26; i++) if (a == (1<<i)-1) {
      printf("%d\n", ans[i]);
      ok = 1;
    }

    if (ok) continue;

    ok = 0;
    for (int i = 0; i < 26; i++)
      if (a&(1<<i)) ok = (1<<(i+1))-1;

    printf("%d\n", ok);
  }
  return 0;
}
