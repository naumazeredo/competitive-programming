#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

ll a, b;
int na=0, nb=0;
int fa=0, fb=0;
int ok=0;

int main() {
  scanf("%lld%lld", &a, &b);

  while (a) {
    if (a%2==0) fa=na+1;
    a/=2;
    na++;
  }

  int c = 0;
  while (b) {
    if (b%2==0) fb=nb+1, c++;
    b/=2;
    nb++;
  }
  ok = (c==1);

  if (na == nb) {
    printf("%d\n", fa - fb + ok);
  } else {
    int c = fa + nb - 1 - fb + ok;
    for (na++; na < nb; ++na) c += na-1;
    printf("%d\n", c);
  }

  return 0;
}
