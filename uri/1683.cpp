#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int n;
char c;
int v[111111];
ll dp[111111];

int main() {
  while (~scanf("%d", &n) and n) {
    cl(dp);
    for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);

    map<int, vi> p;
    for (int i = 1; i <= n; ++i) p[-v[i]].pb(i);

    ll mx = 0;
    for (auto it = p.begin(); it != p.end(); ++it) {
      int h = -it->st;
      for (int i = 0; i < it->nd.size(); ++i) {
        int pos = it->nd[i];
        dp[pos] = dp[pos-dp[pos-1]] = dp[pos+dp[pos+1]] = dp[pos-1]+dp[pos+1]+1;
        mx = max(mx, dp[pos]*h);
      }
    }

    printf("%lld\n", mx);
  }
  return 0;
}
