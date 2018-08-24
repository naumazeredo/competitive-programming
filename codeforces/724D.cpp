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

int n, m;
char s[N];
int ans[300];

int main() {
  scanf("%d%s", &m, s);
  n = strlen(s);

  for (char c = 'a'; c <= 'z'; c++) {
    int ma = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] <= c) cnt = 0;
      else cnt++;
      ma = max(ma, cnt);
    }

    if (ma < m) {
      int l = -1, b = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] < c) {
          l = i;
          ans[s[i]]++;
        }

        if (s[i] == c) b = i;

        if (i - l >= m) {
          l = b;
          ans[s[l]]++;
        }
      }

      for (char i = 'a'; i <= 'z'; i++)
        while (ans[i]--)
          printf("%c", i);
      printf("\n");

      return 0;
    }
  }

  return 0;
}
