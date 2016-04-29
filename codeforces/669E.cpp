#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

const int N = 1000000 + 5;

int n, a, t, x;
map<int, map<int, int> > bit;

int update(int t, int x, int v) {
  while (t < INF) bit[x][t] += v, t += t&-t;
}

int query(int t, int x) {
  int sum = 0;
  while (t) sum += bit[x][t], t -= t&-t;
  return sum;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &a, &t, &x);
    if (a == 1) update(t, x, 1);
    if (a == 2) update(t, x, -1);
    if (a == 3) printf("%d\n", query(t, x));
  }

  return 0;
}
