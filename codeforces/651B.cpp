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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e3+5;

int n, a[N], x;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &x), a[x]++;
  int tot = n, ans = 0;

  while (tot) {
    ans--;
    for (int i = 1; i <= 1000; ++i) if (a[i])
      a[i]--, ans++, tot--;
  }
  printf("%d\n", ans);
  return 0;
}
