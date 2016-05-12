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
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int n;
int px[100005], py[100005];

ll darea(int a, int b, int c) {
  ll dx1 = px[b]-px[a], dy1 = py[b]-py[a];
  ll dx2 = px[c]-px[a], dy2 = py[c]-py[a];
  return abs(dx1*dy2 - dx2*dy1);
}

int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; ++i) scanf("%d%d", &px[i], &py[i]);

    ll totarea = 0;
    for (int i = 2; i < n; ++i) totarea += darea(0, i-1, i);

    ll vol = LINF;
    ll area = 0;
    int i = 0, j = 2;
    while (1) {
      area += darea(i, (n+j-1)%n, j);

      if (2*area >= totarea) {
        vol = min(vol, max(totarea-area, area-darea(i,(n+j-1)%n,j)));
        area -= darea(i, (n+j-1)%n, j);

        j = (n+j-1)%n;
        area -= darea(i, (i+1)%n, j);

        i++;
      }

      j = (j+1)%n;
      if ((i+1)%n == j) j = (j+1)%n;

      if (i == n) break;
    }

    printf("%lld %lld\n", totarea - vol, vol);
  }
  return 0;
}
