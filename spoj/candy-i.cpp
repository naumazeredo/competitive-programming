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
int a[10005];

int main() {
  while (scanf("%d", &n) != EOF and n != -1) {
    int t = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), t += a[i];

    if (t%n) { printf("-1\n"); continue; }
    t/=n;

    int m = 0;
    for (int i = 0; i < n; ++i) m += max(0, t-a[i]);
    printf("%d\n", m);
  }
  return 0;
}
