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
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

char s[1000005];
int dp[1000005][3];

int main() {
  while (scanf(" %s", s) != EOF) {
    int l = strlen(s);
    for (int i = 1; i <= l; ++i) {
      int c = s[i-1]-'0';
      if (c < 0 or c > 9) {
        for (int j = 0; j < 3; ++j)
          dp[i][j] = 0;
      } else {
        for (int j = 0; j < 3; ++j)
          dp[i][j] = dp[i-1][(3+j-(c%3))%3] + (c%3==j);
      }
    }

    /*
    for (int i = 1; i <= l; ++i)
      printf("%d: %d %d %d\n", i, dp[i][0], dp[i][1], dp[i][2]);
      */

    ll res = 0;
    for (int i = 1; i <= l; ++i) res += dp[i][0];
    printf("%lld\n", res);
  }
  return 0;
}
