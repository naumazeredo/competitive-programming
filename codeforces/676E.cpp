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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, MOD2 = 100021981, EPS = 1e-6;
const int N = 1e5+5;

int n, k, a[N], kn[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; ++i) {
    if (scanf("%d", &a[i])==1) kn[i]=1;
    else scanf("%*c");
  }

  int t = 0;
  for (int i = 0; i <= n; ++i) t+=kn[i];

  if (k == 0) {
    if (kn[0]) return 0*printf("%s\n", a[0]?"No":"Yes");
    return 0*printf("%s\n", t%2?"Yes":"No");
  }

  if (t == n+1) {
    ll s0 = 0, s1 = 0, nk = 1;
    for (int i = 0; i <= n; ++i) s0 = (s0+a[i]*nk)%MOD, nk=(nk*k)%MOD;
    nk = 1;
    for (int i = 0; i <= n; ++i) s1 = (s1+a[i]*nk)%MOD2, nk=(nk*k)%MOD2;

    printf("%s\n", (s0 or s1)?"No":"Yes");

    return 0;
  }
  printf("%s\n", t%2?((n+1-t)%2?"Yes":"No"):((n+1-t)%2?"No":"Yes"));
  return 0;
}
