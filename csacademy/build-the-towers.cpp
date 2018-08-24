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
const int N = 1e5+5;

int n, a[N], m[N];
vector<int> p[4];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    p[a[i]].push_back(i);
  }

  vector<int> ans;
  for (int x : p[3]) {
    ans.push_back(x-1);
    ans.push_back(x);
    ans.push_back(x+1);
    ans.push_back(x);
    m[x] = 1;
  }

  for (int x : p[2]) {
    if (x > 1 and !m[x-1]) {
      ans.push_back(x-1);
      ans.push_back(x);
    } else {
      ans.push_back(x+1);
      ans.push_back(x);
    }
    m[x] = 1;
  }

  for (int x : p[1]) ans.push_back(x);

  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x);
  printf("\n");

  return 0;
}
