// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
const int N = 1e5+5;

int n, k, h;
int mrk[N];
vector<int> cand;

int query(int a, int b, int c) {
  printf("? %d %d %d\n", a, b, c);
  fflush(stdout);
  char s[10];
  scanf("%s", s);
  return s[0] == 'Y';
}

void ans(int rt) {
  printf("! %d\n", rt);
  fflush(stdout);
  exit(0);
}

void solve() {
  int h = 0;
  ll t = 0, l = 1;
  while (t < n) {
    t += l;
    l *= k;
    h++;
  }

  for (int i = 0; i < 60; i++) {
    int a = rand()%n+1;
    int b = rand()%n+1;

    vector<int> p;
    for (int j = 1; j <= n; j++) if (query(a, j, b)) p.push_back(j);
    if ((int)p.size() == 2*h-1) {
      for (int x : p) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) cnt += query(a, j, x);
        if (cnt == h) ans(x);
      }
    }
  }
}


int main() {
  srand(time(0));
  scanf("%d%d", &n, &k);
  solve();
  return 0;
}
