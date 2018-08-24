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
const int N = 1e5+5;

char s[20];
int a, b;

int day() {
  if (s[0] == 'm') return 0;
  if (s[0] == 't' and s[1] == 'u') return 1;
  if (s[0] == 'w') return 2;
  if (s[0] == 't' and s[1] == 'h') return 3;
  if (s[0] == 'f') return 4;
  if (s[1] == 'a') return 5;
  return 6;
}

int main() {
  scanf("%s", s);
  a = day();
  scanf("%s", s);
  b = day();

  int ok = 0;
  if (((a+28)%7) == b) ok = 1;
  if (((a+30)%7) == b) ok = 1;
  if (((a+31)%7) == b) ok = 1;
  printf("%s\n", ok ? "YES" : "NO");

  return 0;
}
