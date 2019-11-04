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
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5005, D = 505;

int d, s, inv;
int dp[N][D];
pii r[N][D];

int main() {
  scanf("%d%d", &d, &s);

  memset(r, -1, sizeof r);

  queue<pii> q;

  for (int i = 1; i <= 9; i++) {
    q.push({ i, i%d });
    dp[i][i%d] = 1;
    r[i][i%d] = { 0, 0 };
  }

  while (!q.empty()) {
    int us = q.front().st;
    int um = q.front().nd;
    q.pop();

    for (int i = 0; i <= 9; i++) if (us+i <= s and !dp[us+i][(um*10+i)%d]) {
      q.push({ us+i, (um*10+i)%d });
      dp[us+i][(um*10+i)%d] = 1;
      r[us+i][(um*10+i)%d] = { us, um };
    }
  }

  vector<int> ans;
  d = 0;
  while (r[s][d] != pii(-1, -1)) {
    pii x = r[s][d];
    ans.push_back(s - x.st);
    s = x.st;
    d = x.nd;
  }
  reverse(ans.begin(), ans.end());

  if (ans.size()) {
    for (int x : ans) printf("%d", x);
    printf("\n");
  } else printf("-1\n");

  return 0;
}
