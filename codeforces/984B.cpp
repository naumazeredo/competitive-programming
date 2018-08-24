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
const int N = 1e2+5;

int n, m;
int g[N][N], v[N][N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
    char c;
    scanf(" %c", &c);
    if (c == '*') {
      v[i-1][j-1]++;
      v[i-1][j]++;
      v[i-1][j+1]++;
      v[i][j-1]++;
      v[i][j+1]++;
      v[i+1][j-1]++;
      v[i+1][j]++;
      v[i+1][j+1]++;

      g[i][j] = -1;
    } else if (c >= '1' and c <= '9') {
      g[i][j] = c-'0';
    } else {
      g[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    if (g[i][j] >= 0 and v[i][j] != g[i][j])
      return !printf("NO\n");

  printf("YES\n");

  return 0;
}
