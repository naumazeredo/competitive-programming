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
const int N = 1e5+5;

int n, p[N];
ll inv[N];

int main() {
  for (ll i = 2; i < N; i++) if (!p[i])
    for (ll j = i*i; j < N; j+=i) p[j]=1;

  scanf("%d", &n);
  if (n <= 3) {
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d\n", i);
    return 0;
  }
  if (n == 4) {
    printf("YES\n1\n3\n2\n4\n");
    return 0;
  }

  inv[1] = 1;
  for (int i = 2; i < n; ++i)
    inv[i] = (n - (n/i)*inv[n%i]%n)%n;

  if (p[n]) return printf("NO\n"), 0;

  printf("YES\n");
  printf("1\n");
  for (int i = 2; i < n; i++) printf("%lld\n", (i*inv[i-1])%n);
  printf("%d\n", n);

  return 0;
}
