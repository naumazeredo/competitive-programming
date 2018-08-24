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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int d[10];

ll v, n, t;

void bt(int x) {
  if (x == 10) {
    v += t;
    return;
  }

  if (!d[x]) {
    bt(x+1);
    return;
  }

  for (int i = 1; i <= d[x]; i++) {
    for (int j = 1; j <= i; j++) {
      n++;
      t *= n;
      t /= j;
    }
    bt(x+1);
    for (int j = i; j >= 1; j--) {
      t *= j;
      t /= n;
      n--;
    }
  }
}

int main() {
  scanf("%lld", &n);
  while (n) {
    d[n%10]++;
    n/=10;
  }

  n = 0;
  v = 0;
  t = 1;
  bt(0);

  ll ans = v;

  if (d[0]) {
    d[0]--;

    n = 0;
    v = 0;
    t = 1;
    bt(0);

    ans -= v;

    if (d[0]) {
      n = 0;
      v = 0;
      t = 1;
      bt(1);

      ans -= v;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
