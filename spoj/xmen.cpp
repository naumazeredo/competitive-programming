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

int t, n, x, a[N], b[N];
int l[N], s;

void lis(int u) {
  int p = lower_bound(l, l+s, u) - l;
  l[p] = u;
  if (p == s) s++;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    s = 1; l[0]=-1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &x), a[x] = i;
    for (int i = 0; i < n; ++i) scanf("%d", &x), lis(a[x]);

    printf("%d\n", s-1);
  }
  return 0;
}
