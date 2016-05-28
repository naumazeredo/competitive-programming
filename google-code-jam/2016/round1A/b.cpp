#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))

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

int t, tt, n, x;
int h[3000][100];
int r[3000];

int main() {
  scanf("%d", &t);
  while (tt++ < t) {
    cl(h);
    cl(r);

    scanf("%d", &n);
    for (int i = 0; i < 2*n-1; ++i) for (int j = 0; j < n; ++j) scanf("%d", &x), h[x][j]++;
    vi v;

    for (int i = 1; i < 3000; ++i) for (int j = 0; j < n; ++j) if (h[i][j] == 1) r[i] = 1-r[i];

    printf("Case #%d: ", tt);
    for (int i = 1; i < 3000; ++i) if (r[i]) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
