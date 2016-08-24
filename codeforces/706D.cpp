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
const int N = 2e5+5;

int q;
char c;
ll x;

int trie[N*40][2];
int trien, triev[N*40];

int add(int u, int v) {
  if (trie[u][v]) return trie[u][v];
  return trie[u][v] = ++trien;
}

int main() {
  cl(trie, 0);
  cl(triev, 0);
  trien = 0;

  scanf("%d", &q);

  int u = 0;
  for (int j = 0; j <= 31; ++j) {
    u = add(u, 0);
    triev[u]++;
  }

  for (int i = 0; i < q; ++i) {
    scanf(" %c %lld", &c, &x);

    if (c == '+') {
      int u = 0;
      for (int j = 31; j>=0; --j) {
        int t = (x&(1<<j))>0;
        u = add(u, t);
        triev[u]++;
      }
    }

    if (c == '-') {
      int u = 0;
      for (int j = 31; j>=0; --j) {
        int t = (x&(1<<j))>0;
        u = add(u, t);
        triev[u]--;
      }
    }

    if (c == '?') {
      ll res = 0;
      int u = 0;
      for (int j = 31; j>=0; --j) {
        res *= 2;
        int t = (x&(1<<j))>0;

        if (triev[trie[u][1-t]]) { u = trie[u][1-t]; res += 1; }
        else u = trie[u][t];
      }
      printf("%lld\n", res);
    }
  }
  return 0;
}
