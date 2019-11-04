#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Greatest Common Divisor & Lowest Common Multiple
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a/gcd(a, b)*b; }

void euclid(ll a, ll b, ll &x, ll &y, ll &d) {
  if (b) euclid(b, a%b, y, x, d), y -= x*(a/b);
  else x = 1, y = 0, d = a;
}

// n statements: x == a_i mod b_i
ll norm(ll x, ll mod) { x %= mod; return x<0 ? x+mod : x; }

ll chinese(int n, int a[], int b[], ll& l) {
  ll ans = a[0];
  l = b[0];
  for (int i = 1; i < n; i++) {
    ll x, y, d;
    euclid(l, b[i], x, y, d);
    if ((a[i] - ans) % d != 0) {
      // no solution
      return -1;
    }

    ans = norm(ans + x * (a[i] - ans) / d % (b[i] / d) * l, l * b[i] / d);
    l = lcm(l, b[i]);
  }

  return ans;
}

int t, a[2], n[2];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &a[0], &n[0], &a[1], &n[1]);
    ll l;
    ll ans = chinese(2, a, n, l);
    if (ans == -1) printf("no solution\n");
    else printf("%lld %lld\n", ans, l);
  }
  return 0;
}
