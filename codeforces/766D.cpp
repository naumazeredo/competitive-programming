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

int n, m, q, o[N], t;
char s[40], x[40], y[40];
map<string, int> r;

int p[N], sz[N];


int find(int a) { return p[a]==a?a:p[a]=find(p[a]); }

int opo(int a) { return o[find(a)]; }
int syn(int a, int b) { return find(a) == find(b); }
int ant(int a, int b) { return find(opo(a)) == find(b); }

void unitei(int a, int b) {
  if ((a=find(a)) == (b=find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
}

void unite(int a, int b) {
  a = find(a); b = find(b);
  if (sz[a] < sz[b]) swap(a, b);

  if (opo(b)) {
    if (opo(a)) unitei(opo(a), opo(b));
    else o[a] = opo(b);
  }

  unitei(a, b);
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) scanf("%s", s), r[s] = i, p[i] = i, sz[i] = 1;
  for (int i = 0; i < m; ++i) {
    scanf("%d %s %s", &t, x, y);

    /*
    db(t _ r[x] _ r[y]);
    db(r[x] _ find(r[x]) _ o[find(r[x])]);
    db(r[y] _ find(r[y]) _ o[find(r[y])]);
    */

    if (t == 1) {
      if (ant(r[x], r[y])) printf("NO\n");
      else unite(r[x], r[y]), printf("YES\n");
    }

    if (t == 2) {
      if (syn(r[x], r[y])) printf("NO\n");
      else {
        printf("YES\n");
        if (opo(r[x])) unite(opo(r[x]), r[y]);
        else {
          if (opo(r[y])) unite(opo(r[y]), r[x]);
          else o[find(r[x])] = r[y], o[find(r[y])] = r[x];
        }
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    scanf("%s %s", x, y);
    if (syn(r[x], r[y])) printf("1\n");
    else if (ant(r[x], r[y])) printf("2\n");
    else printf("3\n");
  }
  return 0;
}
