#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

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

int t, tt, m;
char s[30], x[30];

int q[1111111];

int tr[1111111][30];
int trs[1111111];
int trn;

int add(int u, char c) {
  c-='a';
  if (tr[u][c]) return tr[u][c];
  return tr[u][c] = ++trn;
}

int dfs(int u) {
  q[u] += trs[u];
  for (int i = 0; i < 26; ++i) if (tr[u][i]) q[u]+=dfs(tr[u][i]);
  return q[u];
}

int main() {
  scanf("%d", &t);
  while (tt++ < t) {
    memset(tr, 0, sizeof(tr));
    memset(trs, 0, sizeof(trs));
    memset(q, 0, sizeof(q));
    trn = 0;

    scanf(" %s%d", s, &m);
    int len = strlen(s);

    set<string> ss;

    trn = 0;
    for (int i = 1; i <= (1<<len); ++i) {
      bitset<30> b(i);
      int u = 0;
      for (int j = 0; j < len; ++j) if (b[j]) u = add(u, s[j]);
      trs[u]=1;
    }

    dfs(0);

    //for (int i = 0; i <= trn; ++i) db(i _ q[i] _ trs[i]);

    printf("Caso #%d:\n", tt);
    for (int i = 0; i < m; ++i) {
      scanf(" %s", x);
      int u = 0;
      for (int j = 0; x[j]; ++j) {
        u = tr[u][x[j]-'a'];
        if (!u) break;
      }
      if (u) printf("%d\n", q[u]);
      else printf("0\n");
    }
  }
  return 0;
}
