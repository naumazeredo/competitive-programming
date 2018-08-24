#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, k;
ll a[105];

int main() {
  while (~scanf("%d%d", &n, &k)) {
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    vector<ll> v;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) for (int l = j+1; l<n; l++)
      v.push_back(a[i]+a[j]+a[l]);
    sort(v.rbegin(), v.rend());

    printf("%.1Lf\n", v[k-1]/3.0L);
  }
  return 0;
}
