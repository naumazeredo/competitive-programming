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
const int N = 1e7+5;

int n, m;

int main() {
  while (~scanf("%d%d", &n, &m)) {
    int res = 0;
    for (int i = n; i <= m; ++i) {
      int c[10] = {};
      int ok = 1;
      int k = i;
      while (k) {
        if (c[k%10]) { ok = 0; break; }
        c[k%10] = 1;
        k /= 10;
      }
      if (ok) res++;
    }
    printf("%d\n", res);
  }
  return 0;
}
