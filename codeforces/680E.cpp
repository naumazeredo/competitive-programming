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
const int N = 5e2+5;

const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

int n, k, ans;
char g[N][N];

int cc[N*N];
int sz[N*N];

int vis[N*N];

int find(int a) { return cc[a]==a?a:cc[a]=find(cc[a]); }
void unite(int a, int b) {
  if ((a=find(a))==(b=find(b))) return;
  if (sz[b]>sz[a]) swap(a, b);
  sz[a]+=sz[b];
  cc[b]=a;
}

int p(int i, int j) { return i*(n+1)+j; }
void dfs(int i, int j, int c) {
  if (g[i][j]!='.') return;
  int u = p(i,j);
  vis[u]=1;
  unite(u, c);
  for (int a = 0; a < 4; ++a) {
    int ni=i+di[a], nj=j+dj[a];
    int v = p(ni, nj);
    if (!vis[v]) dfs(ni, nj, c);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
    scanf(" %c", &g[i][j]);

  for (int i = 1; i <= (n+1)*(n+1); ++i) cc[i] = i, sz[i]=1;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
    int u = p(i,j);
    if (!vis[u]) dfs(i, j, u);
  }

  for (int i = 1; i <= n-k+1; ++i) {
    int inside[N*N] = {}, totin = 0;
    for (int y = 0; y < k; ++y) for (int x = 0; x < k; ++x) if (g[i+y][1+x]=='.')
      inside[find(p(i+y,1+x))]++;

    int u;
    for (int j = 1; j <= n-k+1; ++j) {
      int tot = k*k;
      bitset<N*N> bs;

      for (int x = 0; x < k; ++x) {
        u = find(p(i-1,j+x));
        if (g[i-1][j+x]=='.' and !bs[u]) tot+=sz[u]-inside[u], bs.set(u);

        u = find(p(i+k,j+x));
        if (g[i+k][j+x]=='.' and !bs[u]) tot+=sz[u]-inside[u], bs.set(u);
      }
      for (int y = 0; y < k; ++y) {
        u = find(p(i+y,j-1));
        if (g[i+y][j-1]=='.' and !bs[u]) tot+=sz[u]-inside[u], bs.set(u);

        u = find(p(i+y,j+k));
        if (g[i+y][j+k]=='.' and !bs[u]) tot+=sz[u]-inside[u], bs.set(u);
      }

      ans = max(ans, tot);

      for (int y = 0; y < k; ++y) {
        u = find(p(i+y,j));
        if (g[i+y][j]=='.') inside[u]--;
        u = find(p(i+y,j+k));
        if (g[i+y][j+k]=='.') inside[u]++;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
