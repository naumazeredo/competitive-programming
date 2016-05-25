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
const int N = 1e3+5;

vector<int> trie[2][N][2];
int trien[2];

int dp[N][N];

char s[50];

int n[2], l;

int add(int t, int u, int c) {
  for (int v : trie[t][u][c]) if (v != 1) return v;
  trie[t][u][c].pb(++trien[t]);
  return trien[t];
}

void go(int i, int j) {
  if (dp[i][j]++) return;

  for (int x = 0; x < 2; ++x)
    for (int u : trie[0][i][x])
      for (int v : trie[1][j][x])
        go(u, v);
}

int main() {
  while (~scanf("%d%d", &n[0], &n[1])) {
    cl(trien,0);
    cl(dp, 0);
    for (int t = 0; t < 2; ++t) for (int i = 0; i < N; ++i) for (int j = 0; j < 2; ++j)
      trie[t][i][j].clear();

    trien[0] = trien[1] = 1;

    for (int t = 0; t < 2; ++t) {
      for (int i = 0; i < n[t]; ++i) {
        scanf(" %s", s);
        l = strlen(s);
        int u = 1;
        for (int j = 0; j < l-1; ++j) {
          u = add(t, u, s[j]-'0');
        }
        trie[t][u][s[l-1]-'0'].pb(1);
      }
    }

    go(1, 1);
    printf("%c\n", dp[1][1]>1?'S':'N');
  }

  return 0;
}
