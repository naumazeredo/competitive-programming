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

int n, b, d, a;

int main() {
  scanf("%d%d%d", &n, &b, &d);
  int s = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (a <= b) {
      s += a;
      if (s > d) s = 0, ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
