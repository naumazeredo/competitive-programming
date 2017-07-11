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
const int N = 1e6+5;

int n, a, c;
int d[N], v[N];
set<pii> x;

int main() {
  scanf("%d%d", &n, &a);

  for (int i = 1; i <= 1000000; i++) x.insert({0, i});

  for (int i = 0; i < n; ++i) {
    scanf("%d", &c);
    if (d[c]) continue;
    x.erase({ v[c], c });
    v[c]++;
    auto p = x.insert({ v[c], c });
    if (c == a) {
      auto it = x.begin();
      for (; it != p.st and it->st < v[a]; it++) d[it->nd] = 1;
      x.erase(x.begin(), it);
    }
  }


  x.erase({ v[a], a });
  if (x.empty()) return 0*printf("-1\n");
  printf("%d\n", x.begin()->nd);

  return 0;
}
