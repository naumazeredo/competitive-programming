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
const int N = 1e5+100;

int n, q, l, r;
ll z;
char s[N];
int trie[N][26], trien, id[N];

vector<int> bit[N];

void add(int p, int v) {
  for (p+=2; p < N; p+=p&-p)
    bit[p].push_back(v);
}

ll query(int p, int l, int r) {
  ll res = 0;
  for (p+=2; p; p-=p&-p)
    res += upper_bound(bit[p].begin(), bit[p].end(), r) - lower_bound(bit[p].begin(), bit[p].end(), l);
  return res;
}

int main() {
  while (~scanf("%d", &n)) {
    z = 0;
    trien = 0;
    memset(trie, 0, sizeof trie);
    memset(id, 0, sizeof id);
    for (int i = 0; i < N; i++) bit[i].clear();

    for (int i = 1; i <= n; i++) {
      scanf("%s", s);
      int u = 0;
      for (int j = 0; s[j]; j++) {
        int c = s[j]-'a';
        if (trie[u][c]) u = trie[u][c];
        else u = trie[u][c] = ++trien;

        add(id[u], i);
        id[u] = i;
      }
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      scanf("%d%d", &l, &r);
      l = (z+l)%n+1;
      r = (z+r)%n+1;
      if (l > r) swap(l, r);

      z = query(l-1, l, r);
      printf("%lld\n", z);
    }
  }
  return 0;
}
