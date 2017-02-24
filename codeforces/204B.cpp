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

int n, c0, c1;
map<int, int> f, b;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &c0, &c1);
    f[c0]++;
    if (c0 != c1) b[c1]++;
  }

  int ans = INF;
  for (auto p : f) {
    if (2 * p.nd >= n) return 0*printf("0\n");
    if (2 * (p.nd + b[p.st]) >= n)
      ans = min(ans, (n+1)/2 - p.nd);
  }

  for (auto p : b) {
    if (2 * (p.nd + f[p.st]) >= n)
      ans = min(ans, (n+1)/2 - f[p.st]);
  }

  printf("%d\n", ans==INF?-1:ans);

  return 0;
}
