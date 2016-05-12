#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int t;
ll n;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    printf("%lld\n", n%3==0?n/3:0);
  }
  return 0;
}
