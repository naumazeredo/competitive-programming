// @subject: 
// @diff: 

#include <bits/stdc++.h>
using namespace std;

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
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ll LINF = 2e18+5;
const int N = 2e5+5;

int n, k, a[N];
int nex[N];
ll ans;

ll mul(ll a, ll b) {
  if (a > LINF/b) return LINF;
  return a*b;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  for (int i = n; i >= 1; i--) {
    if (a[i+1] == 1) nex[i] = nex[i+1];
    else nex[i] = i+1;
  }

  for (int i = 1; i <= n; i++) {
    ll prod = a[i];
    ll sum = a[i];

    if (prod == k*sum) ans++;

    int j = i;
    while (j <= n and prod < LINF) {
      int tot1 = nex[j]-j-1;
      if (tot1) {
        if (prod%k == 0 and k*sum < prod and k*(sum+tot1) >= prod) ans++;;
        sum += tot1;
      }

      j = nex[j];
      if (j > n) break;

      prod = mul(prod, a[j]);
      sum += a[j];

      if (prod == k*sum) ans++;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
