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

int n, k, a[N], t[N], p[N], s[N], v[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);

  for (int i = 1; i <= n; i++) p[i] = p[i-1] + t[i]*a[i];
  for (int i = 1; i <= n; i++) v[i] = v[i-1] + a[i];
  for (int i = n; i >= 1; i--) s[i] = s[i+1] + t[i]*a[i];

  int ans = 0;
  for (int i = 1; i <= n-k+1; i++)
    ans = max(ans, p[i-1] + s[i+k] + v[i+k-1] - v[i-1]);

  printf("%d\n", ans);

  return 0;
}
