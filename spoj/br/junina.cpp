#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, x;

int main() {
  int test = 1;
  while (scanf("%d", &n) != EOF and n) {
    bitset<30> a[30];
    for (int i = 0; i < n; ++i)
      while (scanf("%d", &x) != EOF and x)
        a[i].set(x-1);

    int m = 0;
    for (int i = 1; i < (1<<n); ++i) {
      bitset<30> b(i);
      int ok = 1;
      for (int j = 0; j < n and ok; ++j) if (b[j] and (b&a[j])!=0) ok = 0;
      if (ok) m = max(m, (int)b.count());
    }

    printf("Teste %d\n%d\n\n", test++, m);
  }
  return 0;
}
