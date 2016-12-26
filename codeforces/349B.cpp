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
const int N = 1e5+5;

int n, a[10];

int main() {
  scanf("%d", &n);
  for (int i = 1; i < 10; ++i) scanf("%d", &a[i]);

  int t = 0, d = 0;
  for (int i = 1; i < 10; ++i) {
    if (n/a[i] > t) t = n/a[i], d = i;
    else if (n/a[i] == t and a[i] < a[d]) d = i;
  }

  if (t == 0) return 0*printf("-1\n");

  n -= t*a[d];
  for (int i = 9; i >= d; --i) a[i]-=a[d];

  for (int j = 0; j < t; ++j) {
    int i;
    for (i = 9; i >= d; --i) if (n >= a[i]) break;
    n -= a[i];
    printf("%d", i);
  }
  printf("\n");

  return 0;
}
