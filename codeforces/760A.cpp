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

int m, d;

int main() {
  scanf("%d%d", &m, &d);
  d--;

  d += m==2?28:30;
  if (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12) d++;

  int ans = d/7;
  int r = d%7;
  if (r) ans++;
  printf("%d\n", ans);
  return 0;
}
