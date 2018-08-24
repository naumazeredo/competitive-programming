// @subject: 
// @diff: 

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

int n, m, k, s[N], a[N], p[N];
int last[N];

int solv(int x) {
  int l = 0;
  for (int i = 0; i < n; i++) {
    if (i > l) return 0;
    if (p[i]) l = i+x;
  }
  return l >= n;
}

ll get(int x) {
  ll res = 0;
  int p = 0;
  while (p < n) {
    res += a[x];
    p = x+last[p];
  }
  return res;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i <= n; i++) p[i] = 1;
  for (int i = 0; i < m; i++) scanf("%d", &s[i]), p[s[i]] = 0;
  for (int i = 1; i <= k; i++) scanf("%d", &a[i]);

  for (int i = 1; i <= n; i++)
    last[i] = p[i] ? i : last[i-1];

  if (!solv(k)) return !printf("-1\n");

  int lo = 1, hi = k+1;
  while (lo < hi) {
    int md = (lo+hi)/2;

    if (solv(md)) hi = md;
    else lo = md+1;
  }

  if (lo == k+1) return !printf("-1\n");

  ll ans = 0x3f3f3f3f3f3f3f3f;
  for (int i = lo; i <= k; i++)
    ans = min(ans, get(i));

  printf("%lld\n", ans);

  return 0;
}
