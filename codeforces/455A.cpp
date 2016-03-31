#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

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

int n, x;
ll q[222222];
ll dp[222222];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &x), q[x]+=x;

  dp[0] = 0; dp[1] = q[1];
  for (int i = 2; i < 200000; ++i)
    dp[i] = max(dp[i-1], q[i]+dp[i-2]);

  printf("%lld\n", dp[111111]);

  return 0;
}
