#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int a[5];

int main() {
  while (1) {
    for (int i = 0; i < 5; ++i) if (scanf("%d", &a[i]) == EOF or !a[i]) return 0;

    function<int(int, int)> o[] = {plus<int>(), minus<int>(), multiplies<int>()};
    int b[5] = {0, 1, 2, 3, 4};
    int ok = 1;
    do {
      for (int i = 0; i < 3 and ok; ++i)
      for (int j = 0; j < 3 and ok; ++j)
      for (int k = 0; k < 3 and ok; ++k)
      for (int l = 0; l < 3 and ok; ++l) {
        int res;
        res = o[i](a[b[0]], a[b[1]]);
        res = o[j](res, a[b[2]]);
        res = o[k](res, a[b[3]]);
        res = o[l](res, a[b[4]]);
        ok = !(res == 23);
      }
    } while (next_permutation(b, b+5) and ok);
    if (ok) printf("Impossible\n");
    else printf("Possible\n");
  }
  return 0;
}
