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
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, m;
int b, d, acc, x, t, p;
int v[] = {1, 10, 100, 1000, 10000};

int main() {
  while (~scanf("%d%d", &n, &m)) {
    t = 0, p = 0;
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &b, &d);
      acc = 0;
      for (int j = 0; j < n-1; ++j) scanf("%d", &x), acc+=x;

      if (acc+d <= b) p += d;

      int ma = 0;
      for (int j = 0; j < 5; ++j) if (v[j]+acc <= b) ma = max(ma, v[j]);
      t += ma;
    }

    printf("%d\n", t-p);
  }

  return 0;
}
