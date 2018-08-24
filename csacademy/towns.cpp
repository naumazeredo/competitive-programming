// @subject: 
// @diff: 

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

typedef pair<ld, int> pdi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e4+5;

int n, x, d[N], v[N];

int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; i++) scanf("%d", &d[i]);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);

  set<pdi> s;
  for (int i = 0; i < n; i++) {
    ld t = d[i]/(ld)v[i];
    ld tprime = 1.0l/(1.0l/t + 1.0l/d[i]);
    s.insert({ tprime - t, i });
  }

  for (int i = 0; i < x; i++) {
    int k = s.begin()->second;
    s.erase(s.begin());

    ld t, tprime;
    do {
      i++;
      v[k]++;
      t = d[k]/(ld)v[k];
      tprime = 1.0l/(1.0l/t + 1.0l/d[k]);
    } while ((s.empty() or (tprime - t < s.begin()->first)) and i < x);
    i--;

    t = d[k]/(ld)v[k];
    tprime = 1.0l/(1.0l/t + 1.0l/d[k]);
    s.insert({ tprime - t, k });
  }

  ld ans = 0;
  for (int i = 0; i < n; i++) ans += d[i]/(ld)v[i];
  printf("%.12Lf\n", ans);

  return 0;
}
