#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  for (int i = 0; 2*i < n; ++i) {
    if (i%2) printf("%d ", a[i]);
    else printf("%d ", a[n-i-1]);
  }

  for (int i = n/2-1; i >= 0; --i) {
    if (i%2) printf("%d ", a[n-i-1]);
    else printf("%d ", a[i]);
  }

  printf("\n");

  return 0;
}
