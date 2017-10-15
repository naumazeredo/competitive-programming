#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

// Aho Corasick - <O(sum(m)), O(n + #matches)>
// Multiple string matching

vi elem[N];
int p[N], b[N], nxt[N][256], cnt[N], c[N];
int tsz=1; // size of the trie

void init() {
  tsz=1;
  cl(nxt, 0);
  cl(b, 0);
  cl(cnt, 0);
  for (int i = 0; i < N; i++) elem[i].clear();
}

void add(const string &s, int x) {
  int cur = 1; // the first element of the trie is the root

  for (int i=0; s[i]; ++i) {
    int j = s[i];
    if (!nxt[cur][j]) {
      tsz++;
      p[tsz] = cur;
      c[tsz] = j;
      nxt[cur][j] = tsz;
    }
    cur = nxt[cur][j];
  }

  cnt[cur]++;
  elem[cur].pb(x);
}

void build() {
  queue<int> q;

  for(int i=0; i<256; ++i) {
    nxt[0][i] = 1;
    if (nxt[1][i]) q.push(nxt[1][i]);
  }

  while (!q.empty()) {
    int v = q.front(); q.pop();
    int u = b[p[v]];

    while (u and !nxt[u][c[v]]) u = b[u];
    b[v] = nxt[u][c[v]];
    cnt[v] += cnt[b[v]];

    for (int i = 0; i < 26; ++i) if (nxt[v][i])
      q.push(nxt[v][i]);
  }
}

set<int> match(char *s) {
  set<int> found;
  int x = 1, ans = 0;
  for (int i = 0; s[i]; ++i) {
    int t = s[i];
    while (x and !nxt[x][t]) x = b[x];
    x = nxt[x][t];
    // match found
    //ans += cnt[x];
    for (int k : elem[x]) found.insert(k);
  }
  return found;
}

int tt, n;
char s[N], t[N];

int main() {
  scanf("%d", &tt);
  while (tt--) {
    init();
    scanf("%s%d", s, &n);
    for (int i = 0; i < n; i++) scanf("%s", t), add(t, i);
    build();
    set<int> ans = match(s);
    for (int i = 0; i < n; i++) printf("%c\n", ans.count(i)?'y':'n');
  }
  return 0;
}
