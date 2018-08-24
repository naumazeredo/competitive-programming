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

ll n;

ll solv(ll m) {
  ll x = n;
  ll s = 0;
  while (x) {
    ll t = min(x, m);
    s += t;
    x -= t;
    x -= x/10;
  }
  return s;
}

int main() {
  scanf("%lld", &n);

  ll lo = 1, hi = (n+1)/2;
  while (lo < hi) {
    ll md = (lo+hi)/2;
    if (solv(md) >= (n+1)/2) hi = md;
    else lo = md+1;
  }

  printf("%lld\n", lo);

  return 0;
}
