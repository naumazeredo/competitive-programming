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

ll l, r, k;

int main() {
  scanf("%lld%lld%lld", &l, &r, &k);

  vector<ll> ans;
  for (ll i = 1; 1; i*=k) {
    if (i >= l) ans.pb(i);
    if (i > r/k) break;
  }

  if (!ans.size()) return 0*printf("-1\n");
  for (int i = 0; i < ans.size(); ++i) printf("%lld ", ans[i]);
  printf("\n");

  return 0;
}
