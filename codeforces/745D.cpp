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
const int N = 1e3+5;

int n, ans[N], x, a;

int main() {
  cl(ans,63);

  scanf("%d", &n);

  for (int i = 1; i < n; i*=2) {
    vi v;
    for (int j = 0; j < n; ++j) if ((j/i)%2==0) v.pb(j+1);

    printf("%d\n", (int)v.size());
    for (int x : v) printf("%d ", x);
    printf("\n");
    fflush(stdout);

    for (int j = 0; j < n; ++j) {
      scanf("%d", &a);
      if ((j/i)%2 == 1) ans[j] = min(ans[j], a);
    }
  }

  for (int i = 1; i < n; i*=2) {
    vi v;
    for (int j = 0; j < n; ++j) if ((j/i)%2==1) v.pb(j+1);

    printf("%d\n", (int)v.size());
    for (int x : v) printf("%d ", x);
    printf("\n");
    fflush(stdout);

    for (int j = 0; j < n; ++j) {
      scanf("%d", &a);
      if ((j/i)%2 == 0) ans[j] = min(ans[j], a);
    }
  }

  printf("-1\n");
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  printf("\n");
  fflush(stdout);

  return 0;
}
