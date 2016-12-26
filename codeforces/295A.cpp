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

int n, m, k, l[N], r[N], x, y;
ll a[N], lz[N], lzo[N], d[N];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i <= m; ++i) scanf("%d%d%lld", &l[i], &r[i], &d[i]);
  for (int i = 0; i < k; ++i) scanf("%d%d", &x, &y), lzo[x]++, lzo[y+1]--;

  ll acc = 0;
  for (int i = 1; i <= m; ++i) acc+=lzo[i], lz[l[i]]+=d[i]*acc, lz[r[i]+1]-=d[i]*acc;
  acc = 0;
  for (int i = 1; i <= m; ++i) acc+=lz[i], printf("%lld ", a[i]+acc);
  printf("\n");
  return 0;
}
