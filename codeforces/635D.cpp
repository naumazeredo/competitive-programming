#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int n, k, a[2], q, x, y;
int v[300000][2];
int t[300000][2];

void update(int i, int p, int x) {
  int old = v[p][i];
  v[p][i] = min(a[i], old+x), old -= v[p][i];
  while (p <= n) t[p][i] += -old, p += (p&-p);
}

ll query(int i, int p) {
  ll w = 0;
  while (p) w+=t[p][i], p-=(p&-p);
  return w;
}

int main() {
  scanf("%d%d%d%d%d", &n, &k, &a[0], &a[1], &q);

  for (int i = 0; i < q; ++i) {
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d%d", &x, &y);
      update(0, x, y);
      update(1, x, y);
    } else {
      scanf("%d", &x);
      printf("%lld\n", query(1, x-1) + query(0, n) - query(0, x+k-1));
    }
  }
  return 0;
}
