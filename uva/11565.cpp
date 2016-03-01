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
int a, b, c;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &b, &c);
    int sol = 0;
    int f;
    for (f = 0; f*f < c; ++f);
    for (int x = -f+1; x < a and x*x < c and !sol; ++x)
    for (int y = x+1; x+y < a and x*x + y*y < c and !sol; ++y) {
      int z = a-x-y;
      if (z > y and x*y*z == b and x*x+y*y+z*z == c) sol=1, printf("%d %d %d\n", x, y, z);
    }
    if (!sol) printf("No solution.\n");
  }
  return 0;
}
