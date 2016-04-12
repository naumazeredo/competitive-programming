#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int t, n, a, b;

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    printf("Caso #%d: ", tt);
    a = 0, b =0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (x > y) a += b, b = 0;
      if (x < y) b += a, a = 0;
      if (x == y) a++, b++;
    }
    printf("%d %d\n", a, b);
  }
  return 0;
}
