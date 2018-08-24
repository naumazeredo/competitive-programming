// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e3+5;

int t;
char tmp[N];
string x, y;

int issub() {
  int i, j;
  i = 0, j = 0;

  while (1) {
    if (i >= (int)x.size()) return 1;
    if (j >= (int)y.size()) return 0;
    if (x[i] == y[j]) i++, j++;
    else if (!i) j++;
    else i = 0;
  }

  return 0;
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    printf("Case #%d: ", tt);
    scanf("%s", tmp);
    x = tmp;
    y = tmp;

    size_t p;
    if ((p = x.find(x[0], 1)) != string::npos) y = x.substr(0, p) + x;
    printf("%s\n", issub() ? "Impossible" : y.c_str());
  }
  return 0;
}
