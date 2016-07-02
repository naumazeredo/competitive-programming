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

int n, d;
int g[200][200];

int main() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < d; ++i) for (int j = 0; j < n; ++j) scanf("%1d", &g[i][j]);

  int ans = 0;
  int tot = 0;
  for (int i = 0; i < d; ++i) {
    int t = 0;
    for (int j = 0; j < n; ++j) t+=g[i][j];
    if (t != n) tot++;
    else tot = 0;
    ans = max(ans, tot);
  }

  printf("%d\n", ans);

  return 0;
}
