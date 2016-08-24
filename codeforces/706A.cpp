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

int a, b, n, x, y, v;

ld dist(ld x, ld y) {
  return sqrt(x*x+y*y);
}

int main() {
  scanf("%d%d%d", &a, &b, &n);
  scanf("%d%d%d", &x, &y, &v);
  ld be = dist(x-a, y-b)/v;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &v);
    ld cur = dist(x-a, y-b)/v;
    be = min(be, cur);
  }

  printf("%.9f\n", (double)be);

  return 0;
}
