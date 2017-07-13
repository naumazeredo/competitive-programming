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

int n, c[10*N], l[N], k, x, h;
char s[10*N], t[N];
string ss[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf(" %s%d", t, &k);
    l[i] = strlen(t);
    ss[i] = t;
    for (int j = 0; j < k; j++) {
      scanf("%d", &x); x--;
      if (!c[x] or l[c[x]] < l[i]) c[x] = i, h = max(h, x+l[i]);
    }
  }

  int cur = 0, p = 0;
  for (int i = 0; i < h; i++) {
    if (c[i]) {
      if (!cur or l[cur] - p < l[c[i]]) cur = c[i], p = 0;
    }

    if (cur) {
      s[i] = ss[cur][p];
      p++;
      if (p == l[cur]) cur = 0;
    } else {
      s[i] = 'a';
    }
  }

  printf("%s\n", s);

  return 0;
}
