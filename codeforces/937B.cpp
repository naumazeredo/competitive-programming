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

int p, y;
int pr[N];
vector<int> primes;

int isprime(int x) {
  for (int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++)
    if (x%primes[i] == 0) return 0;
  return 1;
}

int main() {
  scanf("%d%d", &p, &y);

  int ok = 0;
  for (ll i = 2; i <= p and i < N; i++) if (!pr[i]) {
    for (ll j = i*i; j <= p and j < N; j+=i) pr[j]=1;
    primes.push_back(i);
  }

  for (int x = y; x > p; x--) if (isprime(x)) return printf("%d\n", x), 0;
  printf("-1\n");
  return 0;
}
