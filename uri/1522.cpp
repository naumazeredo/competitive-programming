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
const int N = 1e2+5;

int n, v[3][N], m[N][N][N], mex[N];

int go(int a, int b, int c) {
  if (!a and !b and !c) return 1;
  if (~m[a][b][c]) return m[a][b][c];
  int ans = 0;
  for (int i = 1; i < 8; i++) {
    if (!a and (i>>0)&1) continue;
    if (!b and (i>>1)&1) continue;
    if (!c and (i>>2)&1) continue;

    int sum = 0;
    if ((i>>0)&1) sum+=v[0][a];
    if ((i>>1)&1) sum+=v[1][b];
    if ((i>>2)&1) sum+=v[2][c];
    if (sum%3 == 0) ans = max(ans, go(a-((i>>0)&1), b-((i>>1)&1), c-((i>>2)&1)));
  }
  return m[a][b][c] = ans;
}

int main() {
  while (~scanf("%d", &n) and n) {
    cl(m, -1);
    for (int i = n; i >= 1; i--) scanf("%d%d%d", &v[0][i], &v[1][i], &v[2][i]);
    printf("%d\n", go(n, n, n));
  }
  return 0;
}
