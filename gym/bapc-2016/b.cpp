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
const int N = 1e6+5;

char s[N];
int dp[3];

char op(char x) {
  if (x == 'R') return 'S';
  if (x == 'B') return 'K';
  return 'H';
}

int main() {
  scanf("%s", s);

  int sz = 0;
  vector<char> ans;

  for (int i = 0; s[i]; i++) {
    if (sz >= 2) {
      set<char> ss;
      ss.insert(s[i]);
      ss.insert(s[i-1]);
      ss.insert(s[i-2]);
      if (ss.size() == 3) {
        ans.pop_back();
        ans.pop_back();
        ans.push_back('C');
        sz = 0;
      } else {
        ans.push_back(op(s[i]));
        sz++;
      }
    } else {
      ans.push_back(op(s[i]));
      sz++;
    }
  }

  for (char c : ans) printf("%c", c);
  printf("\n");

  return 0;
}
