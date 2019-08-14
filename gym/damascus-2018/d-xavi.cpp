#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-5;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ld memo[20][N];
bool vis[20][N];
int t, n;

ld score(int msk, int gain) {
  int newmsk = msk+gain;
  if((msk & newmsk) == msk) return 0;
  else return (msk ^ newmsk) - gain;
}

ld dp(int i, int msk, ld p) {
  if(msk >= (1 << (i+1))) return 0;
  if(vis[i][msk]) return memo[i][msk];
  if(i <= 1) return memo[i][msk] = 0;

  int num = __builtin_popcount(msk);

  if(num >= i) return memo[i][msk] = 0;

  vis[i][msk] = 1;

  if(msk & 1) {
    memo[i][msk] = p * dp(i-num, 2, p);
    memo[i][msk] += (1.0 - p) * (2.0 * (score(msk, 1)) + dp(i, msk+1, p));
  }
  else {
    memo[i][msk] = p * (2.0 * (score(msk, 2)) + dp(i, msk+2, p));
    memo[i][msk] += (1.0 - p) * (2.0 * (score(msk, 1)) + dp(i, msk+1, p));
  }

  return memo[i][msk];
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);

  while(t--) {
    memset(vis, 0, sizeof vis);
    scanf("%d", &n);
    ld p; scanf("%Lf", &p);

    p /= 100.0;

    printf("%.12Lf\n", dp(n, 0, p));
  }

  return 0;
}
