// @subject: Mobius Function, Number Theory
// @diff: 2

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

const int N = 2e5+5, M = 5e5;

int n, q, a[N], cnt[M], h[N], m[M], t, c1;

int mobius(ll n) {
  int r = 1;
  for (int i = 2; i*i <= n; i++) if (n%i == 0) {
    r = -r;
    n /= i;
    if (n%i == 0) return 0;
  }
  if (n > 1) r = -r;
  return r;
}

int main() {
  for (int i = 1; i <= 5e5; i++) m[i] = mobius(i);

  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  ll ans = 0;
  for (int b, i = 0; i < q; i++) {
    scanf("%d", &b);
    int x = a[b];

    // rem cnt
    if (h[b]) {
      for (int j = 1; j*j <= x; j++) if (x % j == 0) {
        cnt[j]--;
        if (j != x/j) cnt[x/j]--;
      }
    }

    // calc
    ll v = -cnt[1];
    for (int j = 1; j*j <= x; j++) if (x % j == 0) {
      v += m[j] * cnt[j];
      if (j*j != x)
        v += m[x/j] * cnt[x/j];
    }

    // add cnt
    if (!h[b]) {
      for (int j = 1; j*j <= x; j++) if (x % j == 0) {
        cnt[j]++;
        if (j != x/j) cnt[x/j]++;
      }
    }

    if (h[b]) t--, ans -= t + v;
    else      ans += t + v, t++;

    h[b] ^= 1;

    printf("%lld\n", ans);
  }
  return 0;
}
