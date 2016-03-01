#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int p, q, r, s, t, u;

long double si[200005], co[200005], ex[200005], ta[200005], x2[200005];

int main() {
  for (int x = 0; x <= 200000; ++x) {
    si[x] = sin(x/200000.0);
    co[x] = cos(x/200000.0);
    ta[x] = tan(x/200000.0);
    ex[x] = exp(-x/200000.0);
    x2[x] = (x/200000.0)*(x/200000.0);
  }

  while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF) {
    int ok = 0;
    int sol;
    double res = p*ex[0] + q*si[0] + r*co[0] + s*ta[0] + u;
    int pos = res>0;
    for (int x = 0; x <= 200000; ++x) {
      res = p*ex[x] + q*si[x] + r*co[x] + s*ta[x] + t*x2[x] + u;
      if (pos != (res>0)) { sol = x; ok = 1; break; }
      pos = res>0;
    }

    if (ok) printf("%.4f\n", sol/200000.0);
    else printf("No solution\n");
  }
  return 0;
}
