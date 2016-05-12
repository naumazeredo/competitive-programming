#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int d, l, v1, v2;

int main() {
  scanf("%d%d%d%d", &d, &l, &v1, &v2);
  printf("%f\n", (l-d)/double(v1+v2));
  return 0;
}
