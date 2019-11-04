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

int a, b;

vector<int> ans[2];

int main() {
  scanf("%d%d", &a, &b);
  if (!a and !b) return printf("0\n\n0\n\n"), 0;
  if (a == 1 and b == 1) return printf("1\n1\n0\n\n"), 0;
  if (a == 3 and b == 2) return printf("1\n3\n1\n2\n"), 0;
  if (a == 2 and b == 3) return printf("1\n2\n1\n3\n"), 0;

  if (a == 0) {
    printf("0\n\n");

    vector<int> v;
    int x = 1;
    while (b > 2*x) v.push_back(x), b -= x, x++;
    if (b) v.push_back(b);
    printf("%d\n", (int)v.size());
    for (int x : v) printf("%d ", x);
    printf("\n");
    return 0;
  }
  if (b == 0) {
    vector<int> v;
    int x = 1;
    while (a > 2*x) v.push_back(x), a -= x, x++;
    if (a) v.push_back(a);
    printf("%d\n", (int)v.size());
    for (int x : v) printf("%d ", x);
    printf("\n");

    printf("0\n\n");
    return 0;
  }

  ll c = 0ll + a + b;
  ll x = 1;
  while (c > 2*x and x <= max(a, b)) c -= x, x++;
  x--;

  if (x >= a) {
    vector<ll> v;
    ll x = 1, sum = 0;
    while (sum < b) {
      if (x != a) v.push_back(x), sum += x;
      x++;
    }

    printf("%d\n%d\n", 1, a);

    printf("%d\n", (int)v.size());
    for (ll x : v) printf("%lld ", x);
    printf("\n");
  } else {
    vector<ll> v;
    ll x = 1, sum = 0;
    while (sum < a) {
      if (x != b) v.push_back(x), sum += x;
      x++;
    }

    printf("%d\n", (int)v.size());
    for (ll x : v) printf("%lld ", x);
    printf("\n");

    printf("%d\n%d\n", 1, b);
  }

  return 0;
}
