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

int n, a, p[N], dp[N];

int main() {
  for (ll i = 2; i < N; ++i) if (!p[i])
    for (ll j = i*i; j < N; j += i) if (!p[j]) p[j] = i;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);

    int m = 0, v = a;

    while (p[v]) {
      m = max(m, dp[p[v]]+1);
      v = v/p[v];
    }
    m = max(m, dp[v]+1);

    v = a;
    while (p[v]) {
      dp[p[v]] = m;
      v = v/p[v];
    }
    dp[v] = m;

    //db(a _ m);
  }

  int ans = 0;
  for (int i = 0; i < N; ++i)
    ans = max(ans, dp[i]);

  printf("%d\n", ans);

  return 0;
}
