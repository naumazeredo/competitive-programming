#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> li;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int t, n;
int x[30], y[30], p[30];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d%d", &y[i], &x[i], &p[i]);

    ll dist = LINF;
    vector<int> v;

    int i[5];
    for (i[0] = 0; i[0] < 25; ++i[0])
    for (i[1] = i[0]+1; i[1] < 25; ++i[1])
    for (i[2] = i[1]+1; i[2] < 25; ++i[2])
    for (i[3] = i[2]+1; i[3] < 25; ++i[3])
    for (i[4] = i[3]+1; i[4] < 25; ++i[4]) {
      ll s = 0;
      for (int j = 0; j < n; ++j) {
        int m = INF;
        for (int k = 0; k < 5; ++k)
          m = min(m, (abs(i[k]%5-x[j])+abs(i[k]/5-y[j]))*p[j]);
        s += m;
      }

      if (s < dist) {
        dist = s;
        v.clear();
        for (int j = 0; j < 5; ++j)
          v.push_back(i[j]);
      }
    }

    for (int j = 0; j < 5; ++j) printf("%d%c", v[j], j==4?'\n':' ');
  }
  return 0;
}
