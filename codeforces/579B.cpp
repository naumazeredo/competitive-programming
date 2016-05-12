#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;
priority_queue<iii> pq;
int c[1000];

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= 2*n; ++i) {
    for (int j = 1; j < i; ++j) {
      int a;
      scanf("%d", &a);
      pq.push(iii(a, ii(i, j)));
    }
  }

  memset(c, 0, sizeof(c));

  int cnt = 0;
  while (cnt < 2*n) {
    iii v = pq.top(); pq.pop();
    int i = v.second.first;
    int j = v.second.second;
    if (c[i] || c[j]) continue;
    c[i] = j;
    c[j] = i;
    cnt+=2;
  }

  for (int i = 1; i <= 2*n; ++i)
    printf("%d ", c[i]);
  printf("\n");

  return 0;
}
