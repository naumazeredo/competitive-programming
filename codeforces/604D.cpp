#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

ll qp(ll a, ll b, ll mod){
  if(b==0) return 1 % mod;
  ll hold = qp(a%mod,b/2,mod) % mod;
  return (( (hold*hold) % mod )*( b&1 ? a % mod:1 )) % mod;
}

int p, k;
int v[1000005];
int c;

int main() {
  scanf("%d%d", &p, &k);

  for (int i = 1; i < p; ++i) {
    if (v[i]) continue;
    ll s = i;
    while (!v[s]) v[s]=1, s=(s*k)%p;
    c++;
  }

  printf("%lld\n", qp(p, c + (k==1?1:0), 1e9+7));

  return 0;
}
