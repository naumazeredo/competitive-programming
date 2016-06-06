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

int n, h[N], l[N], r[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &h[i]);

  for (int i = 1; i < n; ++i) l[i] = max(l[i-1], h[i-1]);
  for (int i = n-2; i>=0; --i) r[i] = max(r[i+1], h[i+1]);

  int ans = 0;
  for (int i = 0; i < n; ++i) ans += (l[i] > h[i] and r[i] > h[i]);

  printf("%d\n", ans);

  return 0;
}
