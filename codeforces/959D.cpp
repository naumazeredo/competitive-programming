#include <bits/stdc++.h>
using namespace std;

const int N = 5e6+5;

int np[N];
int n, a[N], m[N];
set<int> p;

int main() {
  for (int i = 2; i < N; i++) if (!np[i]) {
    for (int j = i+i; j < N; j += i) np[j] = i;
    np[i] = i;
    p.insert(i);
  }

  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int i;
  for (i = 0; i < n; i++) {
    int x = a[i], ok = 1;
    for (; x != 1 and ok; x /= np[x]) if (!p.count(np[x])) ok = 0;

    if (!ok) {
      int v = a[i]+1;
      while (1) {
        ok = 1;
        x = v;
        for (; x != 1 and ok; x /= np[x]) if (!p.count(np[x])) ok = 0;
        if (ok) break;
        v++;
      }

      printf("%d ", v);

      x = v;
      for (; x != 1; x /= np[x]) p.erase(np[x]);

      i++;
      break;
    }

    x = a[i];
    for (; x != 1; x /= np[x]) p.erase(np[x]);

    printf("%d ", a[i]);
  }

  auto it = p.begin();
  for (; i < n; i++) {
    printf("%d ", *it);
    it++;
  }

  printf("\n");
  return 0;
}
