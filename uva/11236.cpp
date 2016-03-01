#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int main() {
  for (ll a = 1; a <= 500; ++a)
  for (ll b = a; a+b <= 1000; ++b)
  for (ll c = b; a+b+c <= 1500; ++c) {
    ll d;
    if (a*b*c == 1000000) d = 100;
    else d = 1000000*(a+b+c)/(a*b*c-1000000);

    if (d <= 0 || a+b+c+d > 2000 || d < c) continue;
    if (1000000*(a+b+c+d) == a*b*c*d)
      printf("%.2f %.2f %.2f %.2f\n", a/100.0, b/100.0, c/100.0, d/100.0);
  }
  return 0;
}
