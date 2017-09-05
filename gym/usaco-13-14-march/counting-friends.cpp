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
const int N = 1e5+5;

int n, x;
vi v, ans;

// Erdos-Gallai - O(nlogn)
// check if it's possible to create a simple graph (undirected edges) from
// a sequence of vertice's degrees
int gallai(vector<int> v) {
  vector<ll> sum;
  sum.resize(v.size());

  sort(v.begin(), v.end(), greater<int>());
  sum[0] = v[0];
  for (int i = 1; i < v.size(); i++) sum[i] = sum[i-1] + v[i];
  if (sum.back() % 2) return 0;

  for (int k = 1; k < v.size(); k++) {
    int p = lower_bound(v.begin(), v.end(), k, greater<int>()) - v.begin();
    if (p < k) p = k;
    if (sum[k-1] > k*(p-1) + sum.back() - sum[p-1]) return 0;
  }
  return 1;
}

int main() {
  freopen("fcount.in", "r", stdin);
  freopen("fcount.out", "w", stdout);

  scanf("%d", &n);
  for (int i = 0; i < n+1; i++) scanf("%d", &x), v.pb(x);
  vi k;
  for (int i = 1; i < n+1; i++) k.pb(v[i]);

  for (int i = 0; i < n+1; i++) {
    if (gallai(k)) ans.pb(i+1);
    if (i < n) k[i] = v[i];
  }

  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d\n", x);
  return 0;
}
