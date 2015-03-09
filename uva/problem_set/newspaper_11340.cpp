#include <cstdio>
#include <cstring>

int a[300];

char buf[20000];

int main()
{
  char c;
  int n, k, m, t, v;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    memset(a, 0, 300 * sizeof(int));

    scanf("%d", &k);

    for (int j = 0; j < k; ++j)
    {
      getchar();
      scanf("%c %d", &c, &t);
      a[(unsigned char)c] = t;
    }

    v = 0;
    scanf("%d ", &m);
    for (int j = 0; j < m; ++j)
    {
      fgets(buf, 20000, stdin);
      int len = strlen(buf);
      for (int l = 0; l < len; ++l)
        v += a[(unsigned char)buf[l]];
    }

    printf("%d.%02d$\n", v/100, v%100);
  }

  return 0;
}
