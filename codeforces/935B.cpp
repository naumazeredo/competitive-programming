#include <bits/stdc++.h>
using namespace std;

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

int n, x, y, k;
char s[N];

int main() {
  scanf("%d%s", &n, s);
  if (s[0] == 'U') k = 1, y++;
  else k = 0, x++;

  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == 'U') {
      if (x == y and k == 0) ans++, k = 1;
      y++;
    } else {
      if (x == y and k == 1) ans++, k = 0;
      x++;
    }
  }
  printf("%d\n", ans);

  return 0;
}
