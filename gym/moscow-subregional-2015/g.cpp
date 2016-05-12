#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

#define f first
#define s second
#define ff first.first
#define fs first.second

int n;
iii p[200005];
double maxdist;
int a, b;

bool cmp1(iii a, iii b) { return a.ff - b.ff > a.fs - b.fs; }
bool cmp2(iii a, iii b) { return a.ff - b.ff > b.fs - a.fs; }

void proc(double dx, double dy) {
  int g = 0;
  double fa, fb;

  fa = dx*p[0].ff + dy*p[0].fs;

  for (int i = 1; i < n; ++i) {
    fb = dx*p[i].ff + dy*p[i].fs;

    if (fa - fb > maxdist) {
      maxdist = fa - fb;
      a = p[g].s; b = p[i].s;
    }

    if (fb > fa) g = i, fa = fb;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].ff, &p[i].fs), p[i].s = i;

  sort(p, p+n, cmp1);
  proc(1, sqrt(2)-1);
  proc(1, 1-sqrt(2));
  reverse(p, p+n);
  proc(sqrt(2)-1, 1);
  proc(1-sqrt(2), 1);

  sort(p, p+n, cmp2);
  proc(1, sqrt(2)-1);
  proc(1, 1-sqrt(2));
  reverse(p, p+n);
  proc(sqrt(2)-1, 1);
  proc(1-sqrt(2), 1);

  printf("%d %d\n", a+1, b+1);

  return 0;
}
