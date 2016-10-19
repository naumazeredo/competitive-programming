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
const int N = 1e2+5;

int r, c, h[N][N];

void ff(int i, int j, int v) {
  if (h[i][j] != v) return;
  h[i][j] = 0;
  if (i>0) ff(i-1,j,v);
  if (i<r) ff(i+1,j,v);
  if (j>0) ff(i,j-1,v);
  if (j<c) ff(i,j+1,v);
}

int main() {
  while (~scanf("%d%d", &r, &c)) {
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
      scanf("%d", &h[i][j]);

    int ans = 5;

    for (int j = 1; j < c; ++j) ans += h[0][j]>h[0][j-1];
    for (int j = 1; j < c; ++j) {
      for (int i = 1; i < r; ++i) {
        ans += h[i][j] <  h[i-1][j] and h[i][j] > h[i][j-1] and h[i][j] <= h[i-1][j-1];
        ans += h[i][j] >= h[i-1][j] and h[i][j] > h[i][j-1] and (h[i-1][j-1] >= h[i-1][j] or h[i][j-1] >= h[i-1][j]);
      }
    }

    for (int j = 0; j < c-1; ++j) ans += h[r-1][j]>h[r-1][j+1];
    for (int j = 0; j < c-1; ++j) {
      for (int i = 0; i < r-1; ++i) {
        ans += h[i][j] <  h[i+1][j] and h[i][j] > h[i][j+1] and h[i][j] <= h[i+1][j+1];
        ans += h[i][j] >= h[i+1][j] and h[i][j] > h[i][j+1] and (h[i+1][j+1] >= h[i+1][j] or h[i][j+1] >= h[i+1][j]);
      }
    }

    for (int i = 1; i < r; ++i) ans += h[i][c-1]>h[i-1][c-1];
    for (int i = 1; i < r; ++i) {
      for (int j = 0; j < c-1; ++j) {
        ans += h[i][j] <  h[i][j+1] and h[i][j] > h[i-1][j] and h[i][j] <= h[i-1][j+1];
        ans += h[i][j] >= h[i][j+1] and h[i][j] > h[i-1][j] and (h[i-1][j+1] >= h[i][j+1] or h[i-1][j] >= h[i][j+1]);
      }
    }

    for (int i = 0; i < r-1; ++i) ans += h[i][0]>h[i+1][0];
    for (int i = 0; i < r-1; ++i) {
      for (int j = 1; j < c; ++j) {
        ans += h[i][j] <  h[i][j-1] and h[i][j] > h[i+1][j] and h[i][j] <= h[i+1][j-1];
        ans += h[i][j] >= h[i][j-1] and h[i][j] > h[i+1][j] and (h[i+1][j-1] >= h[i][j-1] or h[i+1][j] >= h[i][j-1]);
      }
    }

    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
      if (h[i][j]) ff(i, j, h[i][j]), ans++;

    printf("%d\n", ans);
  }
  return 0;
}
