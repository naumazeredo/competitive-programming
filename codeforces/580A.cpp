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

int n;
int a[222222];
int dp[222222];

int main() {
  scanf("%d", &n);

  a[0] = INF;
  int m = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    dp[i] = (a[i]>=a[i-1]) ? dp[i-1]+1 : 1;
    m = max(m, dp[i]);
  }

  printf("%d\n", m);

  return 0;
}
