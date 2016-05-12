#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5, M = 1e5+1;
int n, t[N], nxt[N][30], m, c;
char s[M][100];


void dfs(int i) {
  for(int j=0; j<30; ++j) {
    if (nxt[i][j]) dfs(nxt[i][j]), t[i] += 1;
  }
}

int main() {
  while(scanf("%d", &n) != EOF) {
    memset(t, 0, sizeof t);
    memset(nxt, 0, sizeof nxt);
    m = 1;
    c = 0;
    for(int k=0; k<n; ++k) {
      scanf(" %s", s[k]);
      int i=1;
      for(int j=0; s[k][j]; ++j) {
        int x = s[k][j]-'a';
        i = nxt[i][x] ? nxt[i][x] : nxt[i][x] = ++m;
      }
      t[i]++;
    }

    dfs(1);

    for(int k=0; k<n; ++k) {
      c++;
      for(int j = 1, i = nxt[1][s[k][0]-'a']; s[k][j]; ++j) {
        if (t[i] > 1) c++;
        i = nxt[i][s[k][j]-'a'];
      }
    }

    printf("%.2f\n", 1.0*c/n);
  }
  return 0;
}
