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
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7+5;

int n, k, c[N], ans[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  priority_queue<pii> pq;
  for (int i = 0; i < k; i++) pq.push({c[i], i});
  ll sum = 0;
  for (int i = k; i < n+k; i++) {
    if (i < n) pq.push({c[i], i});
    pii a = pq.top(); pq.pop();
    ans[a.nd] = i+1;
    sum += 1ll*c[a.nd]*(i-a.nd);
  }

  printf("%lld\n", sum);
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
