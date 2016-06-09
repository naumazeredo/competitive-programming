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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e3+5;

int n, a, t[N], d[N];

int main() {
  scanf("%d%d", &n, &a);
  for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);
  for (int i = 1; i <= n; ++i) d[i] = (a+i<=n?t[a+i]:0) + (a-i>=1?t[a-i]:0);

  int ans = t[a];
  for (int i = 1; i <= n; ++i) {
    if (a+i>n or a-i<1) ans += d[i];
    else ans += d[i]!=1?d[i]:0;
  }
  printf("%d\n",ans);
  return 0;
}
