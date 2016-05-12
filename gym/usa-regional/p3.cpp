#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int p, m, s, init, d, ind;
double a, x, y;

dd p0;
double angle;

bool angle_cmp(dd a, dd b) {
  double d1x = a.first - p0.first, d1y = a.second - p0.second;
  double d2x = b.first - p0.first, d2y = b.second - p0.second;
  return (atan2(d1y, d1x) < atan2(d2y, d2x));
}

int main() {
  scanf("%d", p);
  while (p--) {
    scanf("%d%d%d%d", &d, &m, &s, &init);
    scanf("%f", &a);

    vector<dd> p;
    for (int i = 0; i < m; ++i) {
      scanf("%d", &ind);
      scanf("%d%d", &x, &y);
      p.push_back(dd(x, y));
    }

    int l = 0;
    angle = a * M_PI / 180.0;
    for (int i = 0; i < s; ++i) {
      
    }
  }
  return 0;
}
