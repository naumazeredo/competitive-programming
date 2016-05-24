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
const int N = 1e4+5;

int n;
ll a[N], p[N];

int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), p[i]=p[i-1]+a[i];
    for (int i = n-1; i > 0; --i) for (int j = i+1; j <= n; ++j)
      a[j] = p[j]-p[i-1]-min(a[j-1], a[j]);
    printf("%lld\n", a[n]);
  }
  return 0;
}
