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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int n, nz;
char s[N], t[N];

int main() {
  scanf("%d", &n);
  t[0] = '1';
  for (int i = 0; i < n; ++i) {
    scanf(" %s", s);
    int ok = 1;
    int o = 0;
    for (int j = 0; s[j]; ++j) {
      if ((s[j] != '1' and s[j] != '0') or (s[j] == '1' and o)) { ok = 0; break; }
      o += s[j]=='1';
    }

    if (ok) {
      if (o == 0) return 0*printf("0\n");
      nz += strlen(s)-1;
    } else strcpy(t, s);
  }

  printf("%s", t);
  for (int i = 0; i < nz; ++i) printf("0");
  printf("\n");

  return 0;
}
