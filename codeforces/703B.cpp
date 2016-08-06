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

int n, k, c[N], d, m[N];
ll p[N], pd[N], ans, res;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]), p[i]=p[i-1]+c[i];
  for (int i = 1; i <= k; ++i) scanf("%d", &d), m[d] = 1;
  for (int i = 1; i <= n; ++i) pd[i] = pd[i-1], pd[i] += m[i]*c[i];

  ans += c[n]*c[1];
  for (int i = 2; i <= n; ++i) ans += c[i]*c[i-1];

  for (int i = 1; i <= n; ++i) if (m[i]) {
    int j = (n+i-2)%n+1, k = i%n+1;
    ans += c[i]*(p[n]-c[i]-c[j]-c[k]);
  }

  for (int i = 1; i <= n; ++i) if (m[i]) {
    int j = (n+i-2)%n+1, k = i%n+1;
    res += c[i]*(pd[n]-c[i]-m[j]*c[j]-m[k]*c[k]);
  }

  printf("%lld\n", ans - res/2);

  return 0;
}
