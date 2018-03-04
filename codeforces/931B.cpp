#include <bits/stdc++.h>
using namespace std;

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

int n, a, b;
int t[300];
vector<int> v;

int main() {
  scanf("%d%d%d", &n, &a, &b); a--, b--;

  if (a > b) swap(a, b);
  for (int i = 0; i < n; i++) v.push_back(i);

  int r = 1;
  while (v.size() > 2) {
    vector<int> vv;
    for (int i = 0; i < v.size(); i+=2) {
      if ((v[i] == a and v[i+1] == b) or (v[i] == b and v[i+1] == a))
        return printf("%d\n", r), 0;
      if (v[i+1] == a or v[i+1] == b) vv.push_back(v[i+1]);
      else vv.push_back(v[i]);
    }
    r++;
    v = vv;
  }

  printf("Final!\n");

  return 0;
}
