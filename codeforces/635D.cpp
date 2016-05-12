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
int a[3000];
map<int, int> m;
ll d[5005], s[50005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  sort(a, a+n);
  for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) d[a[j]-a[i]]++;

  ll tot = 0, pre = 0;
  for (int i = 1; i <= 5000; ++i) tot += d[i];
  for (int i = 1; i <= 5000; ++i) s[i] = tot-pre, pre += d[i];

  double res = 0;
  for (int i = 1; i <= 5000; ++i) {
    for (int j = 1; j <= 5000; ++j) {
      res += d[i]*d[j]*s[i+j+1]/double(tot*tot*tot);
    }
  }

  printf("%f\n", res);

  return 0;
}
