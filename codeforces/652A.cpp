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

int x, y;
int a, b;

int main() {
  scanf("%d%d%d%d", &x, &y, &a, &b);
  x -= 4*a;
  if (b >= a and x+12*a < y) return 0*printf("-1\n");
  for (int i = 0; i < 1e6; ++i) {
    if (x > y) return 0*printf("-1\n");
    for (int j = 1; j <= 12; ++j) {
      x += a;
      if (x >= y) return 0*printf("%d\n", i);
    }
    for (int j = 1; j <= 12; ++j) {
      x -= b;
      if (x >= y) return 0*printf("%d\n", i);
    }
  }
  return 0;
}
