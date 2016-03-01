#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int k;

int main() {
  while (scanf("%d", &k) != EOF) {
    int c = 0;
    vector<int> p;
    for (int a = k+1; a <= 2*k; ++a) {
      int b = k*a/(a-k);
      if (a*b == k*(a+b)) p.pb(a), p.pb(b);
    }

    printf("%d\n", (int)p.size()/2);
    for (int i = 0; i < p.size(); i+=2)
      printf("1/%d = 1/%d + 1/%d\n", k, p[i+1], p[i]);
  }
  return 0;
}
