#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int p, d, n;

int main() {
  for (int n = 3; n < 10000; ++n) {
    ll res = 0;

    set<iii> rep;

    for (int a = 1; 2*a <= n; ++a) {
      for (int b = a; 2*b <= n-a; ++b) {
        if (a < n-a && b < n-b && n-a-b < a+b) {
          int c = n-a-b;

          iii r;

          if (a <= b && b <= c) r.first = a, r.second.first = b, r.second.second = c;
          else if (a <= c && c <= b) r.first = a, r.second.first = c, r.second.second = b;
          else if (b <= a && a <= c) r.first = b, r.second.first = a, r.second.second = b;
          else if (b <= c && c <= a) r.first = b, r.second.first = c, r.second.second = a;
          else if (c <= a && a <= b) r.first = c, r.second.first = a, r.second.second = b;
          else  r.first = c, r.second.first = b, r.second.second = a;

          if (rep.find(r) != rep.end()) continue;
          rep.insert(r);

          if (a == b && b == c) res++;
          else if (a == b || a == c || b == c) res++;
          else res+=2;
        }
      }
    }

    printf(", %lld", res);
  }
  return 0;
}
