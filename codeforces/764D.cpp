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
const int N = 5e5+5;

int ok;
int n, x[2], y[2];

int main() {
  scanf("%d", &n);
  printf("YES\n");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) scanf("%d%d", &x[j], &y[j]);
    printf("%d\n", (x[0]&1)+2*(y[0]&1)+1);
  }

  return 0;
}
