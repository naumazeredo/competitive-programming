#include <cstdio>
#include <cstring>

char a[100000][20];
int p[100000];

char buf[2000000];

int main()
{
  int t, n;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i)
  {
    if (i > 0)
      printf("\n");

    getc(stdin); getc(stdin); // ignore \n\n
    fgets(buf, 1000000, stdin);

    int pos = 0;
    for (n = 1; pos < (int)strlen(buf) && sscanf(&buf[pos], "%d", &p[n]) != EOF; n++)
    {
      int num = p[n];
      while (num>0)
      {
        pos++;
        num/=10;
      }
      pos++;
    }
    n--;

    for (int j = 1; j <= n; ++j)
      scanf("%s", a[p[j]]);

    for (int j = 1; j <= n; ++j)
      printf("%s\n", a[j]);
  }

  return 0;
}
