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

const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

int n, m, a[N*N], p[N*N], cc[N*N], sz[N*N], mark[N*N], vis[N*N], ans[N*N], tot, done;
ll k;

int pos(int i, int j) { return i*(m+1)+j; }

int find(int a) { return cc[a]==a?a:cc[a]=find(cc[a]); }
void unite(int a, int b) {
  if ((a=find(a))==(b=find(b))) return;
  if (sz[b]>sz[a]) swap(a,b);
  sz[a]+=sz[b];
  cc[b]=a;
}

void dfs(int i, int j, int val) {
  int u = pos(i,j);
  vis[u]=1;
  ans[u]=val;
  tot--;
  for (int x = 0; x < 4; ++x) {
    int ni = i+di[x], nj = j+dj[x];
    int v = pos(ni, nj);
    if (mark[v] and !vis[v] and tot) dfs(ni, nj, val);
  }
}

int main() {
  scanf("%d%d%lld", &n, &m, &k);
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) scanf("%d", &a[pos(i,j)]);
  for (int i = 0; i <= (n+1)*(m+1); ++i) cc[i]=i, sz[i]=1, p[i]=i;
  sort(p,p+(n+1)*(m+1),[](int i, int j){ return a[i]>a[j]; });

  for (int x = 0; x < n*m; ++x) {
    int b = p[x];
    int i = b/(m+1), j = b%(m+1);

    int u = pos(i,j);
    mark[u] = 1;
    if (mark[pos(i-1, j)]) unite(u, pos(i-1,j));
    if (mark[pos(i+1, j)]) unite(u, pos(i+1,j));
    if (mark[pos(i, j-1)]) unite(u, pos(i,j-1));
    if (mark[pos(i, j+1)]) unite(u, pos(i,j+1));

    if (k%a[u]==0 and 1ll*sz[find(u)]*a[u]>=k) {
      tot = k/a[u], dfs(i, j, a[u]);
      done = 1;
      break;
    }
  }

  if (!done) return 0*printf("NO\n");
  printf("YES\n");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%d ", ans[pos(i,j)]);
    printf("\n");
  }

  return 0;
}
