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
const int N = 205;

int n;
string s[N];
vector<int> vs[N];
char ans[N];

void test(int u, int v) {
  string s0 = s[vs[1][u]] + s[vs[n-1][v]];
  string s1 = s[vs[n-1][1-v]] + s[vs[1][1-u]];

  if (s0 != s1) return;

  string pre, suf;
  for (int i = 0; i < n-1; i++) {
    pre += s0[i];
    suf += s0[n-i-1];

    reverse(suf.begin(), suf.end());

    /**/ if (s[vs[i+1][0]] == pre and s[vs[i+1][1]] == suf) ans[vs[i+1][0]] = 'P', ans[vs[i+1][1]] = 'S';
    else if (s[vs[i+1][0]] == suf and s[vs[i+1][1]] == pre) ans[vs[i+1][0]] = 'S', ans[vs[i+1][1]] = 'P';
    else return;

    reverse(suf.begin(), suf.end());
  }

  printf("%s\n", ans);

  exit(0);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2*n-2; i++) {
    cin >> s[i];
    vs[s[i].length()].push_back(i);
  }

  for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) test(i, j);
  assert(0);

  return 0;
}
