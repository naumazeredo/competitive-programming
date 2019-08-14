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
const int N = 2e3+5;

// Knuth-Morris-Pratt - String Matching O(n+m)
char s[N], p[N];
int b[N], n, m; // n = strlen(s), m = strlen(p);
int rev, mrk[N];

void kmppre() {
  b[0] = -1;
  for (int i = 0, j = -1; i < m; b[++i] = ++j)
    while (j >= 0 and p[i] != p[j])
      j = b[j];
}

void kmp() {
  for (int i = 0, j = 0; i < n;) {
    while (j >= 0 and s[i] != p[j]) j=b[j];
    i++, j++;
    if (j == m) {
      if (!rev) mrk[i-j]=1;
      else mrk[n-i]=1;

      // match position i-j
      j = b[j];
    }
  }
}

char q[N];

int main() {
  scanf("%s%s", s, q);
  n = strlen(s);
  m = strlen(q);

  for (int i = 'a'; i <= 'z'; i++) {
    for (int j = 'a'; j <= 'z'; j++) {
      for (int k = 0; k < m; k++) p[k] = (q[k]=='0' ? i : j);
      kmppre();
      kmp();
    }
  }

  reverse(s, s+n);
  rev = 1;
  for (int i = 'a'; i <= 'z'; i++) {
    for (int j = 'a'; j <= 'z'; j++) {
      for (int k = 0; k < m; k++) p[k] = (q[k]=='0' ? i : j);
      kmppre();
      kmp();
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) ans += mrk[i];
  printf("%d\n", ans);
  return 0;
}
