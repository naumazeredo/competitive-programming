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
typedef vector<vector<pii>> vvii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

char s[N];
int n, p, b;
deque<int> ans;

pii go(int pos, int m, vvii& memo) {
  assert(m >= 0 and m < p);
  auto& r = memo[pos][m];
  if (pos >= n) {
    if (!m) return r = { 0, -1 };
    return r = { -INF+1, -1 };
  }

  if (memo[pos][m].st != -INF) return memo[pos][m];

  int v = s[pos]-'0';

  auto case1 = go(pos+1, m, memo);
  auto case2 = go(pos+1, (10*m + v)%p, memo);

  return r = max(case1, { case2.st + 1, v });
}

void rec(int pos, int m, vvii& memo) {
  assert(m >= 0 and m < p);
  if (pos >= n or memo[pos][m].st <= 0) {
    assert(!m);
    for (int x : ans) printf("%d", x);
    printf("\n");
    return;
  }
 
  int v = s[pos]-'0';
  if (memo[pos][m].nd == v) {
    ans.push_back(v);
    rec(pos+1, (10*m+v)%p, memo);
  } else {
    rec(pos+1, m, memo);
  }
}

int main() {
  scanf("%s%d", s, &p);
  n = strlen(s);

  vvii dp(n+5, vector<pii>(p+5, { -INF, -INF }));

  rng();

  go(0, 0, dp);

  int pos = -1;
  pii best = { -1, -1 };
  for (int i = 0; i < n; i++) if (s[i] != '0') {
    pii d = go(i+1, (s[i]-'0')%p, dp);
    pii state = { d.st+1, s[i]-'0' };
    if (state > best)
      pos = i,
      best = state;
  }

  if (best.st <= 0) {
    int ok = 0;
    for (int i = 0; s[i]; i++) if (s[i]=='0') ok=1;
    if (!ok) printf("-1\n");
    else printf("0\n");
  } else {
    printf("%c", s[pos]);
    /*
    int m = (s[pos]-'0')%p;
    for (int i = pos+1; s[i]; i++) {
      auto d = go(i, m, dp);
      if (d.st <= 0) break;
      if (s[i]-'0' == d.nd) {
        printf("%d", d.nd);
        m = (10*m+s[i]-'0')%p;
      }
    }
    printf("\n");
    */
    //rec(pos, 0, dp);
    rec(pos+1, (s[pos]-'0')%p, dp);
  }

  return 0;
}
