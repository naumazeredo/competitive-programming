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
const int N = 1e2+5;

int n, m, x, v[N];
char s[N][N], p[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i]);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &x), v[x]=1;
    strcpy(p, s[x]);
  }

  for (int i = 1; i <= n; ++i) if (v[i]) {
    if (strlen(s[i]) != strlen(p)) return 0*printf("No\n");
    for (int j = 0; s[i][j]; ++j)
      if (p[j] != '?' and s[i][j] != p[j]) p[j] = '?';
  }

  for (int i = 1; i <= n; ++i) if (!v[i]) {
    if (strlen(s[i]) != strlen(p)) continue;
    int match = 1;
    for (int j = 0; s[i][j]; ++j)
      if (p[j] != '?' and s[i][j] != p[j])
        match = 0;
    if (match) return 0*printf("No\n");
  }

  printf("Yes\n%s\n", p);

  return 0;
}
