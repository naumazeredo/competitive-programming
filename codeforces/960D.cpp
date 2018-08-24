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

int q, t;
ll x, k;
ll sv[100], sn[100], sz[100];

int level(ll x) {
  int res = 0;
  while (x) res++, x/=2;
  return res;
}

void print(ll x) {
  int l = level(x);

  x = x-sz[l];
  x = (sz[l] + x - sv[l]) % sz[l];
  x = x + sz[l];

  while (x) {
    //dbs("");
    //db(l _ x _ sv[l] _ sn[l]);
    ll nx = x-sz[l];
    nx = (nx + sv[l]) % sz[l];
    nx = nx + sz[l];

    printf("%lld ", nx);

    nx = x-sz[l];
    nx = (nx + sn[l]) % sz[l];
    nx = nx + sz[l];

    x = nx/2;
    l--;
  }

  printf("\n");
}

int main() {
  sz[1] = 1;
  for (int i = 2; i <= 62; i++) sz[i] = 2*sz[i-1];

  scanf("%d", &q);
  while (q--) {
    scanf("%d%lld", &t, &x);
    int l = level(x);

    if (t == 1) {
      scanf("%lld", &k);
      k = (sz[l] - k%sz[l]) % sz[l];
      sv[l] = (sv[l] + k) % sz[l];
    }

    if (t == 2) {
      scanf("%lld", &k);
      k = (sz[l] + k%sz[l]) % sz[l];
      sn[l] = (sn[l] + k) % sz[l];
    }

    if (t == 3) print(x);
  }
  return 0;
}
