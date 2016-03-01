#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, b, m, t, a;
int c[30];
bitset<30> bs[30];
int cs[30];

int main() {
  int cas = 1;
  while (scanf("%d%d", &n, &b) != EOF and n and b) {
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d", &t);

      bs[i].reset();
      for (int j = 0; j < t; ++j)
        scanf("%d", &a), bs[i].set(a-1);
      scanf("%d", &cs[i]);
    }

    bitset<30> mbs;
    ll ma = 0;
    for (int i = 0; i < (1<<n); ++i) {
      bitset<30> s(i);
      if (s.count() != b) continue;

      ll v = 0;
      for (int j = 0; j < n; ++j) v += s[j]?c[j]:0;
      for (int j = 0; j < m; ++j) {
        int x = (s&bs[j]).count();
        if (x > 1)
          //v += ((x&1)?1:-1) * (x-1)*cs[j];
          v -= (x-1)*cs[j];
      }

      if (v > ma) {
        ma = v;
        mbs = s;
      } else if (v == ma) {
        int change = 0;
        for (int j = 0; j < n; ++j) {
          if (s[j] and !mbs[j]) { change = 1; break; }
          if (mbs[j] and !s[j]) break;
        }
        if (change) {
          ma = v;
          mbs = s;
        }
      }
    }

    printf("Case Number  %d\n", cas++);
    printf("Number of Customers: %lld\n", ma);
    printf("Locations recommended: ");
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (mbs[i]) printf("%d%c", i+1, cnt<b-1?' ':'\n'), cnt++;
    printf("\n");
  }
  return 0;
}
