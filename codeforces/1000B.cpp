// @subject: prefix sum
// @diff: 2

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

int n, m, a[N], pre[N], s[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[n+1] = m;

  int tot = 0;
  for (int i = 1; i <= n+1; i++) {
    if (i%2) tot += a[i] - a[i-1];
    s[i] = s[i-1] + a[i]-a[i-1];
    pre[i] = tot;
  }

  int ans = tot;
  for (int i = 1; i <= n; i+=2) if (a[i+1]-a[i]>1) ans = max(ans, (m-tot-s[i]+pre[i])+pre[i]-1);
  for (int i = 1; i <= n+1; i+=2) if (a[i]-a[i-1]>1) ans = max(ans, (m-tot-s[i]+pre[i])+pre[i]-1);
  printf("%d\n", ans);

  return 0;
}
