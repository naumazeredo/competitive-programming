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
const int N = 2e5+5;

int n, tx, ty, px[N], py[N], sx[N], sy[N];
char s[N];

int x, y;

void move(char c) {
  if (c == 'U') y++;
  if (c == 'D') y--;
  if (c == 'L') x--;
  if (c == 'R') x++;
}

int test(int x) {
  for (int i = 1; i <= n-x+1; i++) {
    int dx = abs(tx - (px[i-1]+sx[i+x]));
    int dy = abs(ty - (py[i-1]+sy[i+x]));
    int t = x - (dx + dy);

    if (t >= 0 and t%2 == 0) return 1;
  }
  return 0;
}

int main() {
  scanf("%d%s%d%d", &n, s, &tx, &ty);

  x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    move(s[i-1]);
    px[i] = x;
    py[i] = y;
  }

  if (x == tx and y == ty) return printf("0\n"), 0;

  x = 0, y = 0;
  for (int i = n; i > 0; i--) {
    move(s[i-1]);
    sx[i] = x;
    sy[i] = y;
  }

  int lo = 0, hi = n+1;
  while (lo < hi) {
    int md = (lo+hi)/2;

    if (test(md)) hi = md;
    else lo = md+1;
  }

  printf("%d\n", lo == n+1 ? -1 : lo);

  return 0;
}
