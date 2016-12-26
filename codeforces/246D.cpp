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

int n, m, c[N], a, b, x[N];
set<int> s[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]), x[c[i]]=1;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    if (c[a]!=c[b]) s[c[a]].insert(c[b]), s[c[b]].insert(c[a]);
  }

  int b = 0, v = 0;
  for (int i = 1; i < N; ++i) if (x[i] and s[i].size() > b)
    b = s[i].size(), v = i;

  if (!v) for (int i = 1; i < N; ++i) if (x[i]) { v = i; break; }

  printf("%d\n", v);

  return 0;
}
