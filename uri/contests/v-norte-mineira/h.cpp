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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int h, m;
ld x[N], mean, tot;

int main() {
  while (~scanf("%d%d", &h, &m)) {
    mean = 0, tot = 0;

    h *= 60;
    int n = 0;
    for (int i = m; i <= h; i += m, n++) {
      scanf("%Lf", &x[n]);
      mean += x[n];
    }

    mean /= n;

    for (int i = 0; i < n; i++) tot += (x[i]-mean)*(x[i]-mean);
    printf("%.5Lf\n", sqrt(tot/(n-1)));
  }
  return 0;
}
