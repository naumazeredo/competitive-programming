#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

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
const int N = 1e7+5;

int n;
int t[5555];
int c[5555];
int r[5555];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &t[i]);

  for (int i = 0; i < n; ++i) {
    cl(c);
    c[t[i]]++;
    int m = t[i];
    r[m]++;
    for (int j = i+1; j < n; ++j) {
      c[t[j]]++;
      if (c[t[j]] > c[m]) m = t[j];
      else if (c[t[j]] == c[m] and t[j] < m) m = t[j];
      r[m]++;
    }
  }

  for (int i = 1; i <= n; ++i) printf("%d ", r[i]);
  printf("\n");

  return 0;
}
