#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7+5;

int n, k;
int x[1111];
int u[1111];

int main() {
  scanf("%d%d", &n, &k);
  if (n == 4 || k < n+1) return 0*printf("-1\n");

  scanf("%d%d%d%d", &x[0], &x[1], &x[4], &x[2]);
  u[x[0]] = 1;
  u[x[1]] = 1;
  u[x[2]] = 1;
  u[x[4]] = 1;

  int v = 1;
  for (int i = 0; i < n; ++i) {
    if (i <= 2 or i == 4) continue;
    while (u[v]) v++;
    x[i] = v;
    u[v] = 1;
  }

  printf("%d ", x[0]);
  for (int i = n-1; i > 0; --i) printf("%d ", x[i]);
  printf("\n");

  printf("%d ", x[4]);
  for (int i = 5; i < n; ++i) printf("%d ", x[i]);
  printf("%d %d %d %d\n", x[0], x[3], x[1], x[2]);

  return 0;
}
