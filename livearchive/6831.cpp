// @subject: ad-hoc
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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e6+5;

int k, d, s[N], f[N];

int main() {
  while (~scanf("%d%d", &k, &d)) {
    for (int i = 0; i <= 2*k; i++) s[i] = 0, f[i] = 0;

    for (int a, b, i = 0; i < d; i++) {
      scanf("%d%d", &a, &b);
      s[b]=1, f[a]=1;
      s[k+b]=1, f[k+a]=1;
    }

    //for (int i = 1; i <= 2*k; i++) db(i _ s[i] _ f[i]);

    int first = 1, sum = 0, ma_sum = -1;
    for (int i = 1; i <= 2*k; i++) {
      sum += s[i]-f[i];
      if (sum < 0) sum = 0;
      if (sum > ma_sum) ma_sum = sum, first = i;
      //db(i _ sum);
    }

    sum = ma_sum;
    while (sum) {
      sum -= s[first]-f[first];
      first--;
      //db(first _ sum);
    }
    if (first > k) first -= k;
    //db(first);

    ll ans = 1;
    int tot = 1;
    for (int i = first+1; i <= first+k; i++) {
      tot += s[i]-f[i];
      //db(i _ tot _ s[i]);
      if (s[i]) continue;
      ans = (ans * tot) % MOD;
    }

    printf("%lld\n", ans);
  }
  return 0;
}
