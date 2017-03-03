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

int n, m, a[N], dp[N], li[N], k, l, r;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &a[i*m+j]);

  for (int i = 1; i < n; ++i)
    for (int j = 0; j < m; ++j)
      dp[i*m+j] = a[(i-1)*m+j] <= a[i*m+j] ? dp[(i-1)*m+j]+1 : 0,
      li[i] = max(li[i], dp[i*m+j]);

  scanf("%d", &k);
  for (int i = 0; i < k; ++i)
    scanf("%d%d", &l, &r), printf("%s\n", li[r-1]>=r-l?"Yes":"No");

  return 0;
}
