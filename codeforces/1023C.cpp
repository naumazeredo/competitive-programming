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
const int N = 2e5+5;

int n, k;
char s[N];
vector<int> st;
vector<pii> v;

int main() {
  scanf("%d%d%s", &n, &k, s);

  set<pii> ss;
  int sz = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') st.push_back(i);
    else {
      sz += i - st.back() + 1;

      vector<pii> rem;
      for (auto it = ss.lower_bound({ st.back(), 0 });
           it != ss.end() and it->st < i;
           it++) {
        sz -= it->nd - it->st + 1;
        rem.push_back(*it);
      }

      for (auto r : rem) ss.erase(r);

      pii x = { st.back(), i };
      v.push_back(x), st.pop_back();
      ss.insert(x);

      if (sz == k) {
        for (auto x : ss)
          for (int i = x.st; i <= x.nd; i++)
            printf("%c", s[i]);
        printf("\n");
        return 0;
      }
    }
  }

  return 0;
}