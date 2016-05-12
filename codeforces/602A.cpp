#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n, b;
long long x=0, y=0;

int main() {
  scanf("%d%d", &n, &b);
  ll a = 1;
  int c;
  for (int i = 1; i < n; ++i) a *= b;
  for (int i = 0; i < n; ++i) scanf("%d", &c), x += a*c, a/=b;

  scanf("%d%d", &n, &b);
  a = 1;
  for (int i = 1; i < n; ++i) a *= b;
  for (int i = 0; i < n; ++i) scanf("%d", &c), y += a*c, a/=b;


  printf("%c\n", x>y ? '>' : (x<y ? '<' : '='));

  return 0;
}
