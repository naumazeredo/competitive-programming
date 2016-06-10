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
const int N = 1e6+5;

int n, m, a[N], p[N];
map<int, int> c[N], l[N];

int cc[N], sz[N], v[N];

int find(int a) { return cc[a]==a?a:cc[a]=find(cc[a]); }
void unite(int a, int b) {
  if ((a=find(a))==(b=find(b))) return;
  if (sz[b]>sz[a]) swap(a,b);
  sz[a]+=sz[b];
  cc[b]=a;
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n*m; ++i) cc[i]=i, sz[i]=1;
  for (int i = 0; i < n*m; ++i) {
    scanf("%d", &a[i]);
    p[i]=i;

    int y = i/m, x = i%m;
    if (l[y].count(a[i])) unite(l[y][a[i]], i);
    if (c[x].count(a[i])) unite(c[x][a[i]], i);
    l[y][a[i]] = c[x][a[i]] = i;
  }

  for (int i = 0; i < n; ++i) l[i].clear();
  for (int i = 0; i < m; ++i) c[i].clear();

  sort(p, p+n*m, [](int i, int j){ return a[i]<a[j]; });
  for (int i = 0; i < n*m; ++i) {
    int u = p[i];
    int y = u/m, x = u%m;

    int val = 1;
    auto it = l[y].lower_bound(a[u]);
    if (it != l[y].begin()) val = max(val, v[find((--it)->nd)]+1);

    it = c[x].lower_bound(a[u]);
    if (it != c[x].begin()) val = max(val, v[find((--it)->nd)]+1);

    v[find(u)] = max(v[find(u)], val);

    l[y][a[u]] = find(u);
    c[x][a[u]] = find(u);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) printf("%d ", v[find(i*m+j)]);
    printf("\n");
  }

  return 0;
}
