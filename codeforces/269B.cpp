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

int n, m, a[N], l[N];
float f;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d%f", &a[i], &f), l[i] = 1;

  for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j)
    if (a[i] >= a[j]) l[i] = max(l[i], 1+l[j]);

  int ans = 0;
  for (int i = 0; i < n; ++i) ans = max(ans, l[i]);

  printf("%d\n", n-ans);

  return 0;
}
