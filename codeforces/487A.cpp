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

int hp[2], atk[2], def[2], h, a, d;
int ans = INF;

int main() {
  scanf("%d%d%d", &hp[0], &atk[0], &def[0]);
  scanf("%d%d%d", &hp[1], &atk[1], &def[1]);
  scanf("%d%d%d", &h, &a, &d);

  for (int j = def[0]; ; j++) {
    for (int i = max(def[1]+1, atk[0]); ; i++) {
      for (int k = hp[0]; ; k++) {
        int a0 = i - def[1];
        int a1 = max(0, atk[1] - j);

        int t = (hp[1] + a0- 1)/a0;

        if (t * a1 >= k) continue;

        ans = min(ans, a * (i-atk[0]) + d * (j - def[0]) + h * (k - hp[0]));
        break;
      }

      if (i - def[1] >= hp[1]) break;
    }

    if (j > atk[1]) break;
  }

  printf("%d\n", ans);

  return 0;
}
