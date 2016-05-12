#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

const double tol = 1e-10;

ull k;

vector< pair<ull, ull> > s;

int main() {
  scanf("%llu", &k);

  ull n = 1;
  while (n*n*n < 3*k) {
    ull a = 6*k + n*n*n - n,
        b = 3*(n*n+n);
    if (a%b == 0) s.push_back(pair<ull, ull>(n, a/b));

    n++;
  }

  printf("%d\n", (int)(2*s.size()) - (s.back().first==s.back().second));
  for (int i = 0; i < s.size(); ++i)
    printf("%llu %llu\n", s[i].first, s[i].second);
  for (int i = s.size()-1 - (s.back().first==s.back().second); i >= 0; --i)
    printf("%llu %llu\n", s[i].second, s[i].first);
  return 0;
}
