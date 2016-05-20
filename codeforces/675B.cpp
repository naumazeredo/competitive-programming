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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int a[4], n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < 4; ++i) scanf("%d", &a[i]);

  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    int s = i + a[0]+a[1];
    int m[3];
    m[0] = s-a[0]-a[2];
    m[1] = s-a[1]-a[3];
    m[2] = s-a[2]-a[3];
    if (min(m[0], min(m[1], m[2])) > 0 and max(m[0], max(m[1], m[2]))<=n) res++;
  }
  printf("%lld\n", res*n);
  return 0;
}
