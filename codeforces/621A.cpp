#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n;
int a[100005];

int main() {
  scanf("%d", &n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), sum += a[i];

  if (sum%2==0) { printf("%lld\n", sum); return 0; }

  sort(a, a+n);
  for (int i = 0; i < n; ++i) if (a[i]&1) { sum -= a[i]; printf("%lld\n", sum);printf("%lld\n", sum);printf("%lld\n", sum); return 0; }
  return 0;
}
