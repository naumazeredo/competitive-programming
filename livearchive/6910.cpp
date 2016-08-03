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
const int N = 2e4+5;

int t, n, k, p[N], a[N], b[N], ans[N], sz[N];
char c[N];

int find(int a) { return p[a]==a?a:p[a]=find(p[a]); }
void unite(int a, int b) {
  if ((a=find(a))==(b=find(b))) return;
  if (sz[a]<sz[b]) swap(a,b);
  p[b]=a;
  sz[a]+=sz[b];
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    scanf("%d%d", &n, &k);

    cl(ans, 0); cl(a, 0); cl(b, 0); cl(sz, 0);

    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]), p[i]=(p[i]?p[i]:i), sz[i]=1;
    for (int i = 0; i < k; ++i) {
      scanf(" %c", &c[i]);
      if (c[i] == 'C') scanf("%d", &a[i]), b[i]=p[a[i]], p[a[i]]=a[i];
      else scanf("%d%d", &a[i], &b[i]);
    }

    for (int i = 1; i <= n; ++i) unite(i, p[i]);

    for (int i = k-1; i>=0; --i) {
      if (c[i] == 'C') unite(a[i], b[i]);
      else ans[i] = find(a[i])==find(b[i]);
    }

    printf("Case #%d:\n", tt);
    for (int i = 0; i < k; ++i) if (c[i]=='Q') printf("%s\n", ans[i]?"YES":"NO");
  }

  return 0;
}
