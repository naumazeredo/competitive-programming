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
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

int n;
char s[N];

int main() {
  scanf("%s", s);
  n = strlen(s);

  ll ans = 0;
  for (int i = 0; i < n; i++) if (s[i] == 'A') {
    ll b = 0, a = 0;
    for (int j = 0; j < n; j++) if (s[j] == 'Q') {
      if (j < i) b++;
      if (j > i) a++;
    }
    ans += b*a;
  }
  printf("%lld\n", ans);

  return 0;
}
