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

int n, q, l, r;
char s[20];

int trie[1000][26];
set<int> triev[1000];
int trien;

int add(int i, int p, char c) {
  c-='a';
  triev[p].insert(i);
  if (!trie[p][c]) return trie[p][c] = ++trien;
  return trie[p][c];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", s);
    for (int j = 0; s[j]; ++j) for (int k = j; s[k]; ++k) {
      int u = 0;
      for (int v = j; v <= k; ++v)
        u = add(i, u, s[v]);
      triev[u].insert(i);;
    }
  }

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d %s", &l, &r, s);
    int res = 0;

    int u = 0;
    for (int k = 0; s[k]; ++k) {
      u = trie[u][s[k]-'a'];
      if (!u) break;
    }

    res += distance(triev[u].lower_bound(l-1), triev[u].upper_bound(r-1));

    printf("%d\n", res);
  }
  return 0;
}
