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

int n, k;
char s[1005];

bool pal(int l, int r) {
  for (int i = 0; i <= r-l; i++)
    if (s[l+i] != s[r-i])
      return 0;
  return 1;
}

bool solv(int l, int x) {
  if (x == 1) return pal(l, l+n/k-1);
  return pal(l, l+n/k-1) and solv(l+n/k, x-1);
  return 0;
}

int main() {
  scanf("%s%d", s, &k);
  n = strlen(s);

  printf("%s\n", n%k == 0 and solv(0, k) ? "YES" : "NO");

  return 0;
}
