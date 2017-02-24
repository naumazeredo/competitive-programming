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
const int N = 1e4+5;

int n, p[N], par[N], sz[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }
void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b)))
    return;
  if (sz[b] > sz[a]) swap(a, b);
  par[b] = a;
  sz[a]+=sz[b];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]), par[i] = i, sz[i] = 1;
  for (int i = 1; i <= n; ++i) unite(i, p[i]);
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += par[i]==i;
  printf("%d\n", ans);

  return 0;
}
