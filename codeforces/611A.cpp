#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n;

int main() {
  scanf("%d", &n);

  char c;
  for (int i = 0; i < 5; ++i) scanf("%c", &c);

  if (c == 'w') {
    if (n == 5 || n == 6) printf("53\n");
    else printf("52\n");
    return 0;
  } else {
    if (n <= 29) printf("12\n");
    else if (n == 30) printf("11\n");
    else printf("7\n");
  }

  return 0;
}
