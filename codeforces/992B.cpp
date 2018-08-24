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

int l, r, x, y;

int main() {
  scanf("%d%d%d%d", &l, &r, &x, &y);
  if (y%x) return !printf("0\n");
  y /= x;

  vector<int> v;
  for (ll i = 1; i*i <= y; i++) if (y%i == 0) {
    v.push_back(i);
    if (i != y/i) v.push_back(y/i);
  }

  int ans = 0;
  for (int a : v)
    for (int b : v)
      if (l <= a and a <= r and l <= b and b <= r and gcd(a,b) == 1 and 1ll*a*b/gcd(a,b) == y)
        ans++;
  printf("%d\n", ans);

  return 0;
}
