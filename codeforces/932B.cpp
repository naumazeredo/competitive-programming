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
const int N = 1e6+5;

int ans[N][10], n, l, r, k;

int f(int n) {
  int r = 1;
  while (n) {
    if (n%10) r *= n%10;
    n/=10;
  }
  return r;
}

int g(int n) {
  if (n < 10) return n;
  return g(f(n));
}

int main() {
  for (int i = 1; i < N; i++) ans[i][g(i)]=1;
  for (int j = 0; j < 10; j++)
    for (int i = 1; i < N; i++)
      ans[i][j] += ans[i-1][j];

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", ans[r][k] - ans[l-1][k]);
  }

  return 0;
}
