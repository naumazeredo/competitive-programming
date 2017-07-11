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

int n, m, l, r, pre[N], nex[N];

int main() {
  while (~scanf("%d%d", &n, &m) and n and m) {
    nex[0] = 1; pre[n+1] = n;
    for (int i = 1; i <= n; ++i) pre[i] = i-1, nex[i] = i+1;
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &l, &r);
      nex[pre[l]] = nex[r];
      pre[nex[r]] = pre[l];
      if (pre[l]) printf("%d ", pre[l]);
      else printf("* ");
      if (nex[r]!=n+1) printf("%d\n", nex[r]);
      else printf("*\n");
    }
    printf("-\n");
  }
  return 0;
}
