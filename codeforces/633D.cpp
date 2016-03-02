#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int n;
int a[2000];
map<int, int> m;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), ++m[a[i]];

  int ans = 0;
  if (m[0] >= 2) ans = max(ans, m[0]);

  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i != j) {
    int x = a[i], y = a[j];
    if (!x and !y) continue;

    vi v;

    int l = 0;
    while (m.find(x) != m.end() and m[x]) {
      m[x]--;
      l++;
      v.pb(x);

      y = x+y;
      x = y-x;
    }

    ans = max(ans, l);
    for (int k = 0; k < v.size(); ++k) m[v[k]]++;
  }

  printf("%d\n", ans);

  return 0;
}
