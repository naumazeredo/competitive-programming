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

int n, a[N], l[N], r[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  l[0] = 1;
  for (int i = 1; i < n; ++i) l[i] = a[i]>a[i-1]?l[i-1]+1:1;

  r[n-1] = 1;
  for (int i = n-2; i >= 0; --i) r[i] = a[i]<a[i+1]?r[i+1]+1:1;

  int ans = 1;
  for (int i = 0; i < n-1; ++i) ans = max(ans, 1+r[i+1]);
  for (int i = n-1; i > 0; --i) ans = max(ans, 1+l[i-1]);
  for (int i = 1; i < n-1; ++i) if (a[i-1]+1<a[i+1]) ans = max(ans, l[i-1]+1+r[i+1]);

  printf("%d\n", ans);

  return 0;
}
