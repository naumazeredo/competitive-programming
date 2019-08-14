// @subject: 
// @diff: 

#include <bits/stdc++.h>

using namespace std;

std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e4+5, M = 70*N;

int n, q;
char s[10];
string f[N];

int trie[M][40], trien, triev[M], tries[M];

int conv(int c) {
  if (c >= 'a' and c <= 'z') return c - 'a';
  if (c >= '0' and c <= '9') return c - '0' + 26;
  return c = 36;
}

int add(int u, int c) {
  c = conv(c);
  if (trie[u][c]) return trie[u][c];
  return trie[u][c] = ++trien;
}

int step(int u, int c) {
  c = conv(c);
  return trie[u][c];
}

void add(int x) {
  string t = f[x];
  for (int i = 0; t[i]; i++) {
    int u = 0;
    for (int j = i; t[j]; j++) {
      u = add(u, t[j]);
      if (triev[u] != x) tries[u]++;
      triev[u] = x;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    f[i] = s;
    add(i);
  }

  scanf("%d", &q);
  while (q--) {
    scanf("%s", s);
    int u = 0, ok = 1;
    for (int i = 0; s[i] and ok; i++) {
      u = step(u, s[i]);
      if (u == 0) ok = 0;
    }

    if (ok) printf("%d %s\n", tries[u], f[triev[u]].c_str());
    else printf("0 -\n");
  }

  return 0;
}
