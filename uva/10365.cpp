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

int t, n;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    int ans = INF;
    for (int a = 1; a * a <= n; ++a) if (n%a == 0) {
      for (int b = 1; b * b <= n/a; ++b) if ((n/a)%b == 0) {
        int c = n/a/b;
        ans = min(ans, 2*(a*b+a*c+b*c));
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}
