#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int a[4000];

int main() {
  scanf("%d", &n);
  int x = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    x += a[i];
  }

  /*
  printf("%d\n", ((n + 1) * n) / 2 - x);
  */

  sort(a, a+n);

  queue<int> e, q;

  for (int i = 1; i < n; ++i) {
    if      (a[i] == a[i-1]) e.push(a[i]);
    else if (a[i] - a[i - 1] > 1)
      for (int j = a[i-1] + 1; j < a[i] && e.size() > q.size(); ++j)
        q.push(j);
  }

  int m = a[n-1];
  int r = 0;
  while (e.size()) {
    int elem = e.front(); e.pop();
    if (q.size()) {
      r += q.front() - elem;
      q.pop();
    } else {
      m++;
      r += m - elem;
    }
  }

  printf("%d\n", r);
}
