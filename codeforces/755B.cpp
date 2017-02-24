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

int n, m, c;
char s[505];
set<string> w;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", s), w.insert(s);
  for (int i = 0; i < m; ++i) {
    scanf("%s", s);
    if (w.count(s)) c++;
  }

  if (n == m) {
    if (c%2) return 0*printf("YES\n");
    return 0*printf("NO\n");
  }
  if (n < m) return 0*printf("NO\n");
  printf("YES\n");

  return 0;
}
