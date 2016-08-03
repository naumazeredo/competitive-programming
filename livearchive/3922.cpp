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
const int N = 1e3+5;

int r, c, k, a[N][N];
char x;

int main() {
  while (~scanf("%d%d%d", &r, &c, &k) and r) {
    for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j)
      scanf(" %c", &x), a[i][j] = a[i][j-1]+(x=='.');

    int ans = r*c;
    for (int i = 1; i <= c; ++i) {
      for (int j = i; j <= c; ++j) {
        int sum = 0;
        int x = 1, y = 1;
        while (y <= r) {
          while (y <= r and sum<k)
            sum += a[y][j]-a[y][i-1], y++;

          while (x < y and sum>=k)
            ans = min(ans, (j-i+1)*(y-x)),
            sum -= a[x][j]-a[x][i-1], x++;
        }
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}
