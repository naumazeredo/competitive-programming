#include <cstdio>

int e[200000];
int p[200000];
int n, m, k;
long long r;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &e[i]);
    p[e[i]] = i;
  }

  r = 0;
  int a;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a);
    r += ((p[a] - 1) / k) + 1;
    if (p[a] > 1) {
      int e2 = e[p[a]-1];
      p[a]--;
      p[e2]++;
      e[p[a]]=a;
      e[p[e2]]=e2;
    }
  }

  printf("%lld\n", r);

  return 0;
}
