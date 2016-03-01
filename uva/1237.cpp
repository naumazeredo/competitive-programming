#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int t, d, q, p;
int l[20005], h[20005];
char s[20005][40];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &d);
    for (int i = 0; i < d; ++i) scanf(" %s%d%d", s[i], &l[i], &h[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      scanf("%d", &p);
      int ind=-1, c=0;
      for (int j = 0; j < d; ++j) if (p >= l[j] and p <= h[j]) c++, ind=j;
      if (c==1) printf("%s\n", s[ind]);
      else printf("UNDETERMINED\n");
    }
    if (t) printf("\n");
  }
  return 0;
}
