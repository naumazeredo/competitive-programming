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
const int N = 1e6+5;

int n, a, b;
int ans[N];

int main() {
  scanf("%d%d%d", &n, &a, &b);
  if (a == 1 or b == 1) {
    for (int i = 1; i <= n; i++) printf("%d ", i);
    printf("\n");
    return 0;
  }

  int x, y, ok = 0;
  for (y = 0; n >= b*y and !ok; y++) if ((n-b*y) % a == 0) {
    ok = 1;
    x = (n-b*y)/a;
    break;
  }

  if (!ok) {
    printf("-1\n");
    return 0;
  }

  int p = 1;
  for (int i = 0; i < x; i++) {
    ans[p++] = p+a-2;
    for (int j = 1; j < a; j++, p++)
      ans[p] = p-1;
  }

  for (int i = 0; i < y; i++) {
    ans[p++] = p+b-2;
    for (int j = 1; j < b; j++, p++)
      ans[p] = p-1;
  }

  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
