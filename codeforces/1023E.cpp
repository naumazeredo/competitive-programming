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
const int N = 505;

int n, g[N][N];
char res[10];

int get(int r0, int c0, int r1, int c1) {
  printf("? %d %d %d %d\n", r0, c0, r1, c1);
  fflush(stdout);
  scanf("%s", res);
  if (res[0] == 'B') exit(0);
  return res[0] == 'Y';
}

int main() {
  scanf("%d", &n);
  memset(g, -1, sizeof g);

  int r0 = 1, c0 = 1;
  string s, t;
  while (r0 + c0 != n+1) {
    if (r0 < n and get(r0+1, c0, n, n)) r0++, s += 'D';
    else c0++, s += 'R';
  }

  int r1 = n, c1 = n;
  while (r1 != r0 or c1 != c0) {
    if (c1 > c0 and get(1, 1, r1, c1-1)) c1--, t += 'R';
    else r1--, t += 'D';
  }

  reverse(t.begin(), t.end());
  printf("! %s\n", (s+t).c_str());

  return 0;
}
