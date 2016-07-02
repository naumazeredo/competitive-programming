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

const ld EPS = 1e-6, PI = acos(-1);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m;
ll dn[5], dm[5];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 5; ++i) dn[i] = n/5 + (n%5>=i), dm[i] = m/5+(m%5>=i);
  dn[0]--, dm[0]--;
  ll ans = 0;
  ans += dn[0]*dm[0];
  for (int i = 1; i < 5; ++i) ans += dn[i]*dm[5-i];
  printf("%lld\n", ans);
  return 0;
}
