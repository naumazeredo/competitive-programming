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

int a, b, x, y;
set<pii> v;
char s[105];

int main() {
  scanf("%d%d%s", &a, &b, s);
  v.insert({0, 0});
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'U') y++;
    if (s[i] == 'D') y--;
    if (s[i] == 'R') x++;
    if (s[i] == 'L') x--;
    v.insert({x, y});
  }

  for (pii k : v) {
    int nx = x, ny = y, dx = 0, dy = 0;
    if (x) dx = (a-k.st)/x;
    if (y) dy = (b-k.nd)/y;

    if (dx < 0 or dy < 0) continue;
    if (x and dx*x != a-k.st) continue;
    if (y and dy*y != b-k.nd) continue;
    if (x and y and dx != dy) continue;

    nx = k.st + x*dx;
    ny = k.nd + y*dy;
    if (nx == a and ny == b) return 0*printf("Yes\n");
  }
  printf("No\n");

  return 0;
}
