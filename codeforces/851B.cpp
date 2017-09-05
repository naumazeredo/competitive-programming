#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

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

ll x[3], y[3];

ll sq2(int i, int j) {
  ll dx = x[i]-x[j];
  ll dy = y[i]-y[j];
  return dx*dx+dy*dy;
}

int col() {
  ll ux = x[1]-x[0], uy = y[1]-y[0];
  ll vx = x[2]-x[1], vy = y[2]-y[1];

  return ux*vy - uy*vx==0;
}

int main() {
  for (int i = 0; i < 3; i++) scanf("%lld%lld", &x[i], &y[i]);
  if (col()) printf("No\n");
  else printf("%s\n", (sq2(0, 1) == sq2(1, 2))?"Yes":"No");

  return 0;
}
