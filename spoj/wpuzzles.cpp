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
const int N = 1e6+5;

// Aho Corasick - <O(sum(m)), O(n + #matches)>
// Multiple string matching

int p[N], f[N], nxt[N][26], ch[N];
int tsz=1; // size of the trie

int cnt[N]; // used to know number of matches

// used to know which strings matches.
// S is the number of strings. Can use set instead
const int S = 1e3+5;
set<int> elem[N];

void init() {
  tsz=1;
  cl(nxt, 0); cl(f, 0); cl(cnt, 0);
  for (int i = 0; i < N; i++) elem[i].clear();
}

void add(const string &s, int x) {
  int cur = 1; // the first element of the trie is the root

  for (int i=0; s[i]; ++i) {
    int j = s[i] - 'A';
    if (!nxt[cur][j]) {
      tsz++;
      p[tsz] = cur;
      ch[tsz] = j;
      nxt[cur][j] = tsz;
    }
    cur = nxt[cur][j];
  }

  cnt[cur]++; //
  elem[cur].insert(x);
}

void build() {
  queue<int> q;

  for(int i=0; i<26; ++i) {
    nxt[0][i] = 1;
    if (nxt[1][i]) q.push(nxt[1][i]);
  }

  while (!q.empty()) {
    int v = q.front(); q.pop();
    int u = f[p[v]];

    while (u and !nxt[u][ch[v]]) u = f[u];
    f[v] = nxt[u][ch[v]];
    cnt[v] += cnt[f[v]];

    for (int i = 0; i < 26; ++i) if (nxt[v][i])
      q.push(nxt[v][i]);
  }
}

// Return ans to get number of matches
// Return a map (or global array) if want to know how many of each string have matched
map<int, int> match(string s) {
  int ans = 0;    // used to know the number of matches
  map<int, int> found; // used to know which strings matches

  int x = 1;
  for (int i = 0; s[i]; ++i) {
    int t = s[i] - 'A';
    while (x and !nxt[x][t]) x = f[x];
    x = nxt[x][t];

    // match found
    ans += cnt[x];
    for (int k : elem[x]) found[k] = i;
  }

  return found;
}

const int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int tt, l, c, w, ansl[S], ansc[S], ansd[S], sz[S];
char g[S][S], t[S];

int main() {
  scanf("%d", &tt);
  while (tt--) {
    init();

    scanf("%d%d%d", &l, &c, &w);
    for (int i = 0; i < l; i++) for (int j = 0; j < c; j++) scanf(" %c", &g[i][j]);
    for (int i = 0; i < w; i++) scanf("%s", t), add(t, i), sz[i] = strlen(t);
    build();

    for (int i = 0; i < l; i++) {
      for (int k = 1; k <= 3; k++) {
        string s;
        for (int j = 0; j < c and i+j*di[k] >= 0 and i+j*di[k] < l; j++) s += g[i+j*di[k]][j];
        map<int, int> m = match(s);
        for (auto v : m) {
          v.nd -= sz[v.st]-1;
          ansl[v.st] = i+v.nd*di[k];
          ansc[v.st] = 0+v.nd*dj[k];
          ansd[v.st] = k;
        }
      }

      for (int k = 5; k <= 7; k++) {
        string s;
        for (int j = 0; j < c and i+j*di[k] >= 0 and i+j*di[k] < l; j++) s += g[i+j*di[k]][c-j-1];
        map<int, int> m = match(s);
        for (auto v : m) {
          v.nd -= sz[v.st]-1;
          ansl[v.st] = i+v.nd*di[k];
          ansc[v.st] = c-1+v.nd*dj[k];
          ansd[v.st] = k;
        }
      }
    }


    for (int j = 0; j < c; j++) {
      for (int kk = 7; kk <= 9; kk++) {
        int k = kk%8;
        string s;
        for (int i = 0; i < l and j+i*dj[k] >= 0 and j+i*dj[k] < c; i++) s += g[l-1-i][j+i*dj[k]];
        map<int, int> m = match(s);
        for (auto v : m) {
          v.nd -= sz[v.st]-1;
          ansl[v.st] = l-1+v.nd*di[k];
          ansc[v.st] = j+v.nd*dj[k];
          ansd[v.st] = k;
        }
      }

      for (int k = 3; k <= 5; k++) {
        string s;
        for (int i = 0; i < l and j+i*dj[k] >= 0 and j+i*dj[k] < c; i++) s += g[i][j+i*dj[k]];
        map<int, int> m = match(s);
        for (auto v : m) {
          v.nd -= sz[v.st]-1;
          ansl[v.st] = 0+v.nd*di[k];
          ansc[v.st] = j+v.nd*dj[k];
          ansd[v.st] = k;
        }
      }
    }

    for (int i = 0; i < w; i++) printf("%d %d %c\n", ansl[i], ansc[i], ansd[i]+'A');
  }
  return 0;
}
