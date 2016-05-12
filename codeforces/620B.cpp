#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

#define fi first
#define se second

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int a, b;
int v[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
  scanf("%d%d", &a, &b);
  int sum = 0;
  for (int i = a; i <= b; ++i) {
    int x = i;
    while (x) { sum += v[x%10]; x/=10; }
  }

  printf("%d\n", sum);

  return 0;
}
