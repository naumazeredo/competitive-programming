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

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int c, n;
int x[10005];

int main() {
  scanf("%d%d", &c, &n);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);

  int s = c/n;
  double l = x[0], r = x[1];
  while (r-l>EPS) {
    double m = (r+l)/2;
    int ok = 1;
    for (int i = 1; i < n; ++i) {
      if (x[i] <= (i-1)*s+m) {
        ok = 0; r = m; break;
      }
      if (x[i] >= i*s+m) {
        ok = 0; l = m; break;
      }
    }

    if (x[0] <= m-s) ok = 0, r = m;

    if (ok) return 0*printf("S\n");
  }

  printf("N\n");
  return 0;
}
