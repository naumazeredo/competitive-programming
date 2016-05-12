#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

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
const int N = 5e5+5;

int n, k;
int a[N];
ll t, s;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), s+=a[i];

  int l = 0, r = 1e9;
  while (l < r) {
    int m = (l+r)/2;
    t = 0;
    for (int i = 0; i < n; ++i) t += max(a[i]-m, 0);
    if (t > k) l=m+1;
    else r=m;
  }

  int ma = l;

  int extra = s-1ll*ma*n;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= ma) {
      a[i] = ma;
      if (extra) a[i]--, extra--;
    }
  }

  l = 0, r = 1e9;
  while (l < r) {
    int m = (l+r+1)/2;
    t = 0;
    for (int i = 0; i < n; ++i) t += max(m-a[i], 0);
    if (t > k) r=m-1;
    else l=m;
  }

  int mi = l;

  if (mi >= ma) {
    printf("%d\n", s%n!=0);
    return 0;
  }

  printf("%d\n", ma - mi);

  return 0;
}
