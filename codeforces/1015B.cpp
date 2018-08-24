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
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 55;

int n;
char s[N], t[N];

int main() {
  scanf("%d%s%s", &n, s, t);

  vector<int> ans;

  for (int i = 0; i < n; i++) {
    int ok = 0;
    if (s[i] == t[i]) ok = 1;
    for (int j = i+1; j < n and !ok; j++) if (s[j] == t[i]) {
      ok = 1;
      for (int k = j-1; k >= i; k--) {
        ans.push_back(k+1);
        swap(s[k], s[k+1]);
      }
    }

    if (!ok) return !printf("-1\n");
  }

  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x);
  printf("\n");

  return 0;
}
