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
const int N = 1e4+5;

int n;
char s[N];

int pal(string& s) {
  int l = s.length();
  for (int i = 0; i < l; i++)
    if (s[i] != s[l-i-1]) return 0;
  return 1;
}

int check() {
  for (int i = 0; i < n/2; i++) {
    string t;
    for (int j = i+1; j < n; j++) t += s[j];
    for (int j = 0; j <= i; j++) t += s[j];
    if (pal(t) and t != s) return 1;
  }
  return 2;
}

int main() {
  scanf("%s", s);
  n = strlen(s);

  int ok = 0;
  for (int i = 0; s[i]; i++) if (s[i] != s[0]) { ok = 1; break; }

  if (!ok) return printf("Impossible\n"), 0;

  if (n&1) {
    int ok = 0;
    for (int i = 0; i < n/2; i++) if (s[i] != s[0]) { ok = 1; break; }
    if (!ok) return printf("Impossible\n"), 0;
    printf("2\n");
  } else {
    printf("%d\n", check());
    //if (strncmp(s, s+n/2, n/2) != 0) return printf("1\n"), 0;
  }

  return 0;
}
