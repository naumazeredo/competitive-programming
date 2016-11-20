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

char s[N];
int m, p[N], ma[N][30], ans, tot;
ll hp, h, e;
unordered_set<int> sp;

int main() {
  scanf("%s%d", s, &m);

  for (int i = 0; i < m; ++i) scanf("%d", &p[i]);

  for (int i = 1; i <= 26; ++i) {
    hp = 0;
    for (int j = 0; j < m; ++j)
      hp = (hp * 31 + (p[j]==i))%MOD;
    if (hp) sp.insert(hp), tot++;
  }

  for (int i = 0; i < 26; ++i) {
    h = 0; e = 1;
    int j;
    for (j = 0; j < m; ++j)
      h = (h * 31 + (s[j]==i+'a'))%MOD,
      e = (e * 31)%MOD;

    if (sp.count(h)) ma[m-1][i] = 1;

    for (j = m; s[j]; ++j) {
      h = (h * 31 + (s[j]==i+'a'))%MOD;
      h = (MOD + h - e * (s[j-m]==i+'a'))%MOD;

      if (sp.count(h)) ma[j][i] = 1;
    }
  }

  for (int i = 0; s[i]; ++i) {
    int cnt = 0;
    for (int j = 0; j < 26; ++j) cnt += ma[i][j];
    if (cnt == tot) ans++;
  }

  printf("%d\n", ans);

  return 0;
}
