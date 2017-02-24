#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int k, a, b;

int main() {
  scanf("%d%d%d", &k, &a, &b);
  int cnt = a/k + b/k;
  int sa = a/k, sb = b/k;
  a%=k; b%=k;
  if (sa == 0 and b) return 0*printf("-1\n");
  if (sb == 0 and a) return 0*printf("-1\n");
  printf("%d\n", cnt);
  return 0;
}
