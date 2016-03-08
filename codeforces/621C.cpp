#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n, p;
ll l[100005], r[100005];
ll x[100005];

int main() {
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; ++i) scanf("%lld%lld", &l[i], &r[i]), x[i] = r[i]/p - (l[i]-1)/p;

  double t = 0;
  for (int i = 0; i < n; ++i) t += x[i]*4000/double(r[i]-l[i]+1);
  for (int i = 0; i < n; ++i) t -= x[i]*x[(i+1)%n]*2000/double(r[i]-l[i]+1)/double(r[(i+1)%n]-l[(i+1)%n]+1);
  printf("%lf\n", t);
  return 0;
}
