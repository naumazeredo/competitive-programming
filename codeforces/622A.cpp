#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

ll n;

int main() {
  scanf("%lld", &n);
  int i = 1;
  while (n>0) n-=i, i++;
  n+=i-1;
  printf("%lld\n", n);
  return 0;
}
