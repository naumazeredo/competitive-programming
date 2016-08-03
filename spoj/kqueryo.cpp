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
const int N = 3e5+5, SQ = 200;

int n, q, l, r, k, a[N];
vi blocks[SQ];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    blocks[i/SQ].pb(a[i]);
  }
  for (int i = 0; i < SQ; ++i) sort(blocks[i].begin(), blocks[i].end());

  scanf("%d", &q);

  int ans = 0;
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d", &l, &r, &k);
    l = (l^ans), r = (r^ans), k = (k^ans);
    if (l<1) l = 1;
    if (r>n) r = n;
    if (l>r) {
      ans = 0;
      printf("%d\n", ans);
      continue;
    }
    l--, r--;

    ans = 0;
    if (l/SQ == r/SQ) {
      for (int j = l; j <= r; ++j) ans += a[j]>k;
    } else {
      for (int j = l; j < (l/SQ+1)*SQ; ++j) ans += a[j]>k;
      for (int j = (r/SQ)*SQ; j <= r; ++j) ans += a[j]>k;

      for (int j = l/SQ+1; j < r/SQ; ++j)
        ans += blocks[j].end() - upper_bound(blocks[j].begin(), blocks[j].end(), k);
    }
    printf("%d\n", ans);
  }
  return 0;
}
