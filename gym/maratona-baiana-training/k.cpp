#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 300009
#define MAXM 10000009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x));
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
#define MAXS 2009

int l[MAXN], r[MAXN];
int n;

ll simulate(int x) {
  ll ans = 0;
  FOR(i, n) {
    if (x < l[i]) {
      ans += l[i] - x;
      x = l[i];
    }
    if (x > r[i]) {
      ans += x - r[i];
      x = r[i];
    }
  }
  return ans;
}

int main() {
  int last = -1, mr = INF, ml = -INF;
  scanf("%d", &n);
  FOR(i, n) {
    scanf("%d %d", &l[i], &r[i]);
  }
  FOR(i, n) {
    if (min(mr, r[i]) < max(ml, l[i])) {
      break;
    }
    mr = min(mr, r[i]);
    ml = max(ml, l[i]);
  }
  ll ans = min(simulate(ml), simulate(mr));
  printf("%lld\n", ans);
  return 0;
}
