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

int n, a[N], b[N], ans[2];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%1d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%1d", &b[i]);
  sort(a,a+n); sort(b,b+n);

  int l = 0, r = n-1;
  for (int i = 0; i < n; ++i) {
    if (b[i] < a[l]) r--, ans[0]++;
    else l++;
  }

  for (int i = n-1; i >= 0; --i) {
    for (int j = n-1; j >= 0; --j) if (a[j] < b[i]) {
      ans[1]++; a[j]=INF; break;
    }
  }

  printf("%d\n%d\n", ans[0], ans[1]);

  return 0;
}
