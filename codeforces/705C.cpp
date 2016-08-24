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
const int N = 3e5+5;

int n, q, t, x, mi, res, tot;
queue<int> no[N], qi, qt;

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &t, &x);

    if (t == 1) {
      res++;

      tot++;
      no[x].push(tot);

      qi.push(x);
      qt.push(tot);
    }

    if (t == 2) {
      while (!no[x].empty()) no[x].pop(), res--;
    }

    if (t == 3) {
      while (!qt.empty() and qt.front() <= x) {
        int qu = qi.front(); qi.pop();
        int pos = qt.front(); qt.pop();
        if (!no[qu].empty() and no[qu].front() == pos) res--, no[qu].pop();
      }
    }

    printf("%d\n", res);
  }

  return 0;
}
