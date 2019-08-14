// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
const int N = 2e6+5;

int n;
int trie[N][2], trien, triecnt[N][2];

int add(int u, int v) {
  if (!trie[u][v]) trie[u][v] = ++trien;
  return trie[u][v];
}

int main() {
  scanf("%d", &n);

  ll ans = 0;
  int s = 0;

  int u = 0;
  for (int j = 0; j < 21; j++) u = add(u, !!(s&(1<<j)));
  triecnt[u][0]++;

  for (int a, i = 1; i <= n; i++) {
    scanf("%d", &a);
    s ^= a;

    u = 0;
    for (int j = 0; j < 21; j++) u = add(u, !!(s&(1<<j)));

    ans += triecnt[u][i&1];
    triecnt[u][i&1]++;
  }
  printf("%lld\n", ans);
  return 0;
}
