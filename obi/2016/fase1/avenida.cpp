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

int n, m, c[N], x;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &x), c[j]+=x;

  int mi = INF;
  for (int i = 0; i < m; ++i) mi = min(mi, c[i]);

  printf("%d\n", mi);

  return 0;
}
