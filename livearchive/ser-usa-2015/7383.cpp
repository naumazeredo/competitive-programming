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

const ld EPS = 1e-6, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7+5;

int e, s, f, dp[N];

int main() {
  while (~scanf("%d%d%d", &e, &s, &f)) {
    for (int i = 1; i <= e; i++) dp[i] = min(1 + (i-s>0?dp[i-s]:0) + (i-f>0?dp[i-f]:0), INF);
    double d = 225.0/(dp[e]+1)<25.0?200.0/dp[e]:225.0/(dp[e]+1);
    printf("%.6f\n", d);
  }
  return 0;
}
