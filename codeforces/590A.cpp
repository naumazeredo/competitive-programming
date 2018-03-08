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
const int N = 5e5+5;

int n, a[N], ans;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int i = 0;
  while (i < n-1) {
    while (i < n-1 and a[i] == a[i+1]) i++;
    if (i == n-1) break;

    int j = i+1;
    while (j < n and a[j] != a[j-1]) j++;
    j--;
    ans = max(ans, (j-i)/2);

    for (int k = i+1; k <= (i+j)/2; k++) a[k] = a[i];
    for (int k = (i+j)/2+1; k < j; k++) a[k] = a[j];

    i = j;
  }

  printf("%d\n", ans);
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");

  return 0;
}
