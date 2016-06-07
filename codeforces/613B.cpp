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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int n, a, cf, cm, x[N], p[N];
ll m, ps[N], ss[N];
ll bi, bmi, bq, bt;

int main() {
  scanf("%d%d%d%d%lld", &n, &a, &cf, &cm, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]), p[i]=i;

  bmi = INF;
  for (int i = 0; i < n; ++i) bi += (x[i]==a), bmi=min(bmi, 1ll*x[i]);
  bt = 1ll*bi*cf+1ll*bmi*cm;
  bq = 0;

  sort(p,p+n,[](int i, int j) { return x[i] < x[j]; });

  ps[0] = 0, ss[0] = 0;
  for (int i = 1; i < n; ++i) ps[i] = ps[i-1]+(x[p[i]]-x[p[i-1]])*i;
  for (int i = 1; i <= n; ++i) ss[i] = ss[i-1]+(a-x[p[n-i]]);

  for (int i = 0; i <= n and m >= ss[i]; ++i) {
    ll nm = m, mi;
    nm -= ss[i];
    int q = lower_bound(ps, ps+n-i, nm)-ps;
    q--;
    if (q>=0) {
      nm -= ps[q];
      mi = min(1ll*a, (nm/(q+1))+x[p[q]]);
      nm -= (mi-x[p[q]])*(q+1);
    }

    ll t = 1ll*i*cf + 1ll*mi*cm;
    if (t >= bt) {
      bt = t;
      bi = i;
      bmi = mi;
      bq = q;
    }
  }

  for (int i = 0; i < bq+1; ++i) x[p[i]] = bmi;
  for (int i = 0; i < bi; ++i) x[p[n-i-1]] = a;

  printf("%lld\n", bt);
  for (int i = 0; i < n; ++i) printf("%d ", x[i]);
  printf("\n");

  return 0;
}
