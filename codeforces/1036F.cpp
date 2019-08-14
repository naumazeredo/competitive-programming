// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6+5, M = 65;

int t, m[M], p[N];
ll n, c[N];
vector<ll> v[M];

void pre() {
  for (int i = 1; i < M; i++) m[i] = 1;
  for (int i = 2; i < M; i++) if (!p[i]) {
    for (int j = i; j < M; j++) {
      p[j] = 1;
      m[j] *= -1;
      if ((j/i) % i == 0) m[j] = 0;
    }
  }

  for (int i = 2; i < N; i++) c[i] = i * i;

  for (int i = 3; i < M; i++)
    for (int j = 2; j < N; j++)
      if (c[i] < LINF / i)
        v[i].push_back(c[i]), c[i] *= i;
}

ll solv(ll x) {
  ll res = x-1;

  ll sq = max<ll>(1, sqrt(x)-2);
  while (sq*sq <= n) sq++; sq--;
  res -= sq-1;

  for (int i = 3; i < M; i++) {
    int qnt = upper_bound(v[i].begin(), v[i].end(), x) - v[i].begin();
    res += m[i] * qnt;
  }

  return res;
}

int main() {
  pre();

  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    printf("%lld\n", solv(n));
  }
  return 0;
}
