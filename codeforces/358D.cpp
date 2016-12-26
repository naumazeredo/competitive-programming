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

int n, a[N][3], p[N][2];

int main() {
  scanf("%d", &n);
  for (int j = 0; j < 3; ++j) for (int i = 0; i < n; ++i) scanf("%d", &a[i][j]);

  p[0][0] = a[0][0];
  p[0][1] = a[0][1];
  for (int i = 1; i < n; ++i) {
    p[i][0] = max(p[i-1][0] + a[i][1], p[i-1][1] + a[i][0]);
    p[i][1] = max(p[i-1][0] + a[i][2], p[i-1][1] + a[i][1]);
  }

  printf("%d\n", p[n-1][0]);

  return 0;
}
