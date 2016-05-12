#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int p, d, b;
char num[10000005];

int main() {
  scanf("%d", &p);
  while (p--) {
    scanf("%d%d", &d, &b);
    scanf(" %s", num);

    ll res = 0;
    int cb = 1;
    for (int i = strlen(num)-1; i >= 0; --i) {
      int digit = num[i]-'0';
      res = (res+digit*cb)%(b-1);
      cb = (cb*cb)%(b-1);
    }

    printf("%d %lld\n", d, res);
  }

  return 0;
}
