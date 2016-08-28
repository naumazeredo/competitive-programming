#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, a, x[N];

int main() {
  scanf("%d%d", &n, &a);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  sort(x,x+n);

  if (n == 1) return 0*printf("0\n");
  if (n == 2) return 0*printf("%d\n", min(abs(a-x[0]), abs(a-x[1])));
  if (a <= x[0]) return 0*printf("%d\n", x[n-2]-a);
  if (a >= x[n-1]) return 0*printf("%d\n", a-x[1]);

  int ans;
  ans = a-x[0]+x[n-2]-x[0];
  ans = min(ans, x[n-1]-a+x[n-1]-x[1]);
  ans = min(ans, abs(a-x[1])+x[n-1]-x[1]);
  ans = min(ans, abs(a-x[n-2])+x[n-2]-x[0]);

  printf("%d\n", ans);

  return 0;
}
