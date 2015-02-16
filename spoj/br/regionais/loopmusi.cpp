#include <cstdio>

int main()
{
  int n;

  while (scanf("%d", &n) && n)
  {
    int picos = 0;
    int hs[10000];

    for (int i = 0; i < n; ++i)
      scanf("%d", &hs[i]);

    for (int i = 0; i < n; ++i)
    {
      int pre = (i == 0) ? n - 1 : i - 1;
      int nex = (i == n -1) ? 0 : i + 1;

      if ((hs[i] > hs[pre] && hs[i] > hs[nex]) ||
          (hs[i] < hs[pre] && hs[i] < hs[nex]))
        picos++;
    }

    printf("%d\n", picos);
  }

  return 0;
}
