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

int n, k;
char ans[4][N];

int main() {
  scanf("%d%d", &n, &k);
  memset(ans, '.', sizeof ans);

  int i = 1;
  for (; k/2; i++, k-=2)
    ans[1][i] = ans[2][i] = '#';

  if (k) {
    db(k _ i _ n);
    if ((n-i)%2 == 0 and i > 1) {
      i--;
      ans[1][i] = ans[2][i] = '.';
      k+=2;
    }

    int c = (i+n-1)/2;
    ans[1][c] = '#';
    if (k > 1) ans[1][c-1] = ans[1][c+1] = '#';
  }

  if (ans[1][n-1] == '#') ans[1][n-1] = '.', ans[2][n-2] = '#';

  printf("YES\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) printf("%c", ans[i][j]);
    printf("\n");
  }

  return 0;
}
