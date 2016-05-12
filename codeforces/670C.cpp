#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int n, m;
int a[N], b[N], c[N];

map<int, int> g;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), g[a[i]]++;
  scanf("%d", &m);

  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &c[i]);

  int ind = 0;
  int ma1 = g[b[0]], ma2 = g[c[0]];
  for (int i = 1; i < m; ++i) {
    if (ma1 < g[b[i]] or (ma1 == g[b[i]] and ma2 < g[c[i]])) {
      ind = i;
      ma1 = g[b[i]];
      ma2 = g[c[i]];
    }
  }

  printf("%d\n", ind+1);

  return 0;
}
