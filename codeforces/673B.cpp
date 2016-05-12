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
const int N = 1e5+5;

int n, m, u, v;
int a[N];

int main() {
  scanf("%d%d", &n, &m);
  int maxx = 1, miny = n;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    if ((max(u, v) < maxx) || (min(u, v) > miny) ||
        (a[min(u, v)] == 2) || (a[max(u, v)] == 1))
      return 0*printf("0\n");

    a[min(u, v)] = 1;
    a[max(u, v)] = 2;
    maxx = max(maxx, min(u, v));
    miny = min(miny, max(u, v));
  }

  printf("%d\n", miny - maxx);

  return 0;
}
