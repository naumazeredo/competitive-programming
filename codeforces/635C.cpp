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
typedef pair<ll, ll> pll;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int s[64], x[64];
int n;

ll dp[64][2];

ll go(int i, int c) {
  if (x[i] xor s[i] xor c) return 0;
  if (i >= n) return !c;
  if (dp[i][c]) return dp[i][c];

  if (!x[i]) return dp[i][c] = go(i+1,0) + go(i+1,1);
  return dp[i][c] = 2*go(i+1,c);
}

int main() {
  ll a, b;
  scanf("%lld%lld", &a, &b);
  ll va=a, vb=b;
  while (a or b) {
    s[n] = a%2;
    x[n] = b%2;
    a/=2; b/=2;
    n++;
  }

  printf("%lld\n", go(0,0) - (va==vb?2:0));

  return 0;
}
