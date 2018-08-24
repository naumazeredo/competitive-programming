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
const int N = 1e2+5;

int n;
int g[4][N][N];
int v[4];

int main() {
  scanf("%d", &n);
  for (int p = 0; p < 4; p++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%1d", &g[p][i][j]);

  for (int p = 0; p < 4; p++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        v[p] += ((i+j)&1)^g[p][i][j];

  int ans = INF;
  vector<int> vec;
  vec.push_back(0); vec.push_back(0);
  vec.push_back(1); vec.push_back(1);

  do {
    int val = 0;
    for (int i = 0; i < 4; i++)
      val += vec[i] ? n*n - v[i] : v[i];
    ans = min(ans, val);
  } while (next_permutation(vec.begin(), vec.end()));

  printf("%d\n", ans);

  return 0;
}
