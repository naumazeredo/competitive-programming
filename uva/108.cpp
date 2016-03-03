#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int n;
int a[200][200];

int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
      scanf("%d", &a[i][j]), a[i][j] += (j>0?a[i][j-1]:0);

    for (int i = 1; i < n; ++i) for (int j = 0; j < n; ++j)
      a[i][j] += a[i-1][j];

    int m = -INF;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
      for (int x = i; x < n; ++x) for (int y = j; y < n; ++y)
        m = max(m, a[x][y]-(i>0?a[i-1][y]:0)-(j>0?a[x][j-1]:0)+(i>0&&j>0?a[i-1][j-1]:0));

    printf("%d\n", m);
  }
  return 0;
}
