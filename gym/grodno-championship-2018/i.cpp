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

int n, z;
ld c[100][100], p2[100];

int main() {
  for (int i = 0; i < 100; i++) c[i][0] = 1;
  for (int i = 1; i < 100; i++)
    for (int j = 1; j < 100; j++)
      c[i][j] = c[i-1][j-1] + c[i-1][j];

  p2[0] = 1;
  for (int i = 1; i < 100; i++) p2[i] = 2*p2[i-1];

  while (~scanf("%d%d", &n, &z)) {
    if (z > n) { printf("100\n"); continue; }
    ld tot = 0;
    for (int i = 0; i <= z; i++) tot += p2[n-i]/p2[n-z]*c[n][i]/c[n][z];
    printf("%.12Lf\n", (1.0 - 1.0/tot) * 100);
  }
  return 0;
}
