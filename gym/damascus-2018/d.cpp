// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 19, M = (1<<N);

int t, n, pp, cnt;
int vis[N][M];
double p, dp[N][M];
int sc[M][5], bits[M];

int calc(int m, int a) { return (m^(m+a))-a; }
double go(int m, int n) { // :( stack overflow
  if (bits[m] >= n) return 0;
  if (vis[n][m] == cnt) return dp[n][m];
  vis[n][m] = cnt;

  double& r = dp[n][m];
  r = (1-p) * (sc[m][2] + go(m+2, n));
  if (m&2) r += p * go(4, n-bits[m]);
  else r += p * (sc[m][4] + go(m+4, n));

  return r;
}

double go_stack(int n) {
  vector<pii> s;
  s.push_back({ n, 0 });

  while (s.size()) {
    auto x = s.back();
    int n = x.st;
    int m = x.nd;

    if (vis[n][m] == cnt) {
      s.pop_back();
      continue;
    }
    vis[n][m] = cnt;
    dp[n][m] = 0;
    if (bits[m] >= n) {
      s.pop_back();
      continue;
    }

    if (!vis[n][m+2]) {
      s.push_back({ n, m+2 });
      continue;
    } else {
      dp[n][m] += (1-p) * (sc[m][2] + dp[n][m+2]);
    }

    if (m&2) {
      if (!vis[n-bits[m]][4]) {
        s.push_back({ n-bits[m], 4 });
        continue;
      } else {
        dp[n][m] += p * dp[n-bits[m]][4];
      }
    } else {
      if (!vis[n][m+4]) {
        s.push_back({ n, m+4 });
        continue;
      } else {
        dp[n][m] += p * (sc[m][4] + dp[n][m+4]);
      }
    }
    s.pop_back();

    /*
    if (k == 0) {
      s.push_back({ { m, n }, 1 });
      s.push_back({ { m+2, n }, 0 });
    } else if (k == 1) {
      dp[n][m] += (1-p) * (sc[m][2] + dp[n][m+2]);

      if (m&2) {
        s.push_back({ { m, n }, 2 });
        s.push_back({ { 4, n-bits[m] }, 0 });
      } else {
        s.push_back({ { m, n }, 3 });
        s.push_back({ { m+4, n }, 0 });
      }
    } else if (k == 2) {
      dp[n][m] += p * dp[n-bits[m]][4];
    } else if (k == 3) {
      dp[n][m] += p * (sc[m][4] + dp[n][m+4]);
    }
    */
  }

  return dp[n][0];
}

int main() {
  scanf("%d", &t);
  for (int i = 0; i < M; i++) {
    sc[i][2] = calc(i, 2);
    sc[i][4] = calc(i, 4);
    bits[i] = __builtin_popcount(i);
  }

  while (t--) {
    cnt++;

    scanf("%d%d", &n, &pp); p = pp/100.0;
    printf("%.12f\n", go_stack(n));
  }
  return 0;
}
