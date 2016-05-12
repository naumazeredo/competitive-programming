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
int a[30];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  for (int i = 0; i < n; ++i) {
    sort(a, a+n);
    for (int j = 0; j < n-1; ++j) if (a[j] == a[j+1]) a[j]--;
  }

  ll t = 0;
  for (int i = 0; i < n; ++i) if (a[i] > 0) t+=a[i];
  printf("%lld\n", t);

  return 0;
}
