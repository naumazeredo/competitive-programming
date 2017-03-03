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

int n;
char s[N];
string ss[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf(" %s", s), ss[i] = s;

  for (int i = n-2; i >= 0; --i) {
    int d = 0;
    for (; ; ++d) {
      if (ss[i][d] < ss[i+1][d]) { d = -1; break; }
      if (ss[i][d] > ss[i+1][d]) break;
      if (!ss[i][d]) break;
    }
    if (~d) ss[i].resize(d);
  }

  for (int i = 0; i < n; ++i) printf("%s\n", ss[i].c_str());

  return 0;
}
