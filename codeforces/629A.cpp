#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n;
char g[200][200];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf(" %s", g[i]);

  ll s=0;
  for (int i = 0; i < n; ++i) {
    ll x = 0;
    for (int j = 0; j < n; ++j) x+=g[i][j]=='C';
    s += x*(x-1)/2;
    x=0;
    for (int j = 0; j < n; ++j) x+=g[j][i]=='C';
    s += x*(x-1)/2;
  }
  printf("%lld\n", s);
  return 0;
}
