#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

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
const int N = 1e7+5;

int n, t;

int main() {
  scanf("%d", &n);
  int x = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    if (t - x > 15) return 0*printf("%d\n", x + 15); 
    x = t;
  }
  x = min(x + 15, 90);

  printf("%d\n", x);
  return 0;
}
