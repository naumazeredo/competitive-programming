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

int n, v[N];

int main() {
  while (~scanf("%d", &n) and n) {
    while (~scanf("%d", &v[1]) and v[1]) {
      for (int i = 2; i <= n; i++) scanf("%d", &v[i]);

      int j = 1;
      vector<int> s;
      for (int i = 1; i <= n; i++) {
        s.push_back(i);
        while (s.size() and s.back() == v[j]) {
          db(j);
          s.pop_back();
          j++;
        }
      }

      printf("%s\n", j == n+1 and s.empty() ? "Yes" : "No");
    }
    printf("\n");
  }
  return 0;
}
