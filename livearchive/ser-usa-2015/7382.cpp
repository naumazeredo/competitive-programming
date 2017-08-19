#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

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

int c[300], cnt;
char s[105];

int main() {
  while (~scanf("%s", s)) {
    cl(c,0); cnt = 0;
    for (int i = 0; s[i]; i++) cnt += !c[s[i]], c[s[i]]++;
    int ans = 0;
    while (cnt > 2) {
      int ii, mi = INF;
      for (int i = 0; i < 256; i++) if (c[i] and mi > c[i]) mi = c[i], ii = i;
      ans += mi;
      c[ii] = 0;
      cnt--;
    }
    printf("%d\n", ans);
  }
  return 0;
}
