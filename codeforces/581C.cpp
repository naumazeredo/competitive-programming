#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n, k;

int t;
priority_queue<ii> pq;

int main() {
  scanf("%d%d", &n, &k);

  t = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    t += a/10;
    pq.push(ii(a%10-10, a));
  }

  while (k && !pq.empty()) {
    ii e = pq.top(); pq.pop();
    //printf("k %d e %d %d\n", k, e.first, e.second);
    if (e.second == 100) continue;

    if (k >= -e.first) {
      k += e.first;
      t++;
      int a = e.second - e.first;
      pq.push(ii(-10, a));
    } else {
      break;
    }
  }

  printf("%d\n", t);

  return 0;
}
