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

int n, a[N], p[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);

  if (n == 1 and a[1] == 0) return !printf("No\n");
  if (n >= 2 and a[1] == 0 and a[2] == 0) return !printf("No\n");
  if (n >= 2 and a[n] == 0 and a[n-1] == 0) return !printf("No\n");

  p[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i-1]) p[i] = 1 + p[i-1];
    else p[i] = 1;
  }
  //for (int i = 1; i <= n; i++) db(i _ a[i] _ p[i]);

  for (int i = 1; i <= n; i++) {
    if (a[i] and p[i] > 1) return !printf("No\n");
    if (!a[i] and p[i] > 2) return !printf("No\n");
  }
  printf("Yes\n");
  return 0;
}
