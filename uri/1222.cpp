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

int n, l, c;
char s[100];

int main() {
  while (~scanf("%d%d%d", &n, &l, &c)) {
    int lc = 0, cc = -1;
    for (int i = 0; i < n; ++i) {
      scanf(" %s", s);
      int len = strlen(s);
      if (cc + len+1 > c) cc = -1, lc++;
      cc += len+1;
    }

    printf("%d\n", 1+lc/l);
  }
  return 0;
}
