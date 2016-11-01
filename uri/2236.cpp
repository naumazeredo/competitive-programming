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
const int INF = 0x3f3f3f3f, MOD = 1e9+7, SQ = 320;
const int N = 1e5+5;

int n, q, x, k[N], l[N], r[N], p[N], ans[N];
vi adj[N];
int bit[N];

void add(int p, int v) { for (p+=2; p < N; p+=p&-p) bit[p]+=v; }
int sum(int p) {
  p+=2;
  int sum = 0;
  for (; p; p-=p&-p) sum+=bit[p];
  return sum;
}

void dfs(int u, int m) {
  k[u] = m;
  for (auto v : adj[u]) if (!k[v]) dfs(v, m);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &x), adj[x].pb(i);
  for (int i = 0; i < q; ++i) scanf("%d%d", &l[i], &r[i]), p[i] = i;
  sort(p, p+q, [](int a, int b){ return l[a]/SQ == l[b]/SQ ? r[a] < r[b] : l[a] < l[b]; });

  for (int i = 1; i <= n; ++i) if (!k[i]) dfs(i, i);

  int cl = 0, cr = -1;
  for (int i = 0; i < q; ++i) {
    int ind = p[i];
    while (cr < r[ind]) add(k[++cr], +1);
    while (cr > r[ind]) add(k[cr--], -1);
    while (cl < l[ind]) add(k[cl++], -1);
    while (cl > l[ind]) add(k[--cl], +1);

    int t = r[ind]-l[ind]+1;
    int lo = 1, hi = n;
    while (lo < hi) {
      int mid = (lo+hi)/2;
      int prof = sum(mid);
      if (prof > t - prof) hi = mid;
      else lo = mid+1;
    }

    int res = lo-1;
    int d1 = abs(t - 2*sum(res)), d2 = abs(t - 2*sum(res+1));
    if (d2 < d1) res++;
    res = sum(res);

    lo = 1, hi = n;
    while (lo < hi) {
      int mid = (lo+hi)/2;
      if (sum(mid) >= res) hi = mid;
      else lo = mid+1;
    }

    ans[ind] = lo;
  }

  for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);

  return 0;
}
