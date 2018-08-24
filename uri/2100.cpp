#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;

const int N = 5e3+5;
const ll MOD = 1300031;

int t, n, m;
ll fat[N], p2[N];

ll fexp(ll a, ll b) {
  ll r = 1;
  for (a %= MOD; b; a=(a*a)%MOD, b>>=1) if (b&1) r = (r*a)%MOD;
  return r;
}

int main() {
  fat[0] = 1;
  for (int i = 1; i < N; i++) fat[i] = (fat[i-1]*i)%MOD;

  p2[0] = 1;
  for (int i = 1; i < N; i++) p2[i] = (p2[i-1]*2)%MOD;

  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);

    ll ans = p2[m]*fat[n-m]%MOD;
    ans = ans*fexp(fat[n-2*m], MOD-2)%MOD;

    printf("%lld\n", ans);
  }
  return 0;
}
