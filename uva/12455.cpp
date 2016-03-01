#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int t, n, p;
int a[30];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < p; ++i) scanf("%d", &a[i]);

    int s[2000] = {};
    s[0] = 1;
    for (int i = 0; i < p; ++i) for (int j = n; j >= 0; --j) if (s[j] and a[i]+j <= n) s[a[i]+j]=1;

    printf("%s\n", s[n]?"YES":"NO");
  }
  return 0;
}
