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
const int N = 2e5+5;

int n, l[N], r[N], p[N], ans[N];
vi v;
int bit[2*N];

void add(int x) { x+=2; while (x<=2*N) bit[x]++, x+=x&-x; }
int query(int x) {
  x+=2;
  int sum = 0;
  while (x) sum+=bit[x], x-=x&-x;
  return sum;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &l[i], &r[i]), p[i]=i, v.pb(l[i]), v.pb(r[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; ++i) l[i] = lower_bound(v.begin(), v.end(), l[i])-v.begin()+1;
  for (int i = 0; i < n; ++i) r[i] = lower_bound(v.begin(), v.end(), r[i])-v.begin()+1;

  sort(p, p+n, [](int i, int j) { return r[i]<r[j]; });
  for (int i = 0; i < n; ++i) {
    int u = p[i];
    ans[u] = query(r[u])-query(l[u]-1);
    add(l[u]);
  }

  for (int i = 0; i < n; ++i) printf("%d\n", ans[i]);

  return 0;
}
