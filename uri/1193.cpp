#include <cstdio>
#include <cstring>

char buffer[10000];

int main()
{
  int n, t;
  char s[10], sn[10000];
  int test = 1;

  scanf("%d ", &t);

  for (int a = 0; a < t; ++a)
  {
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%s %s", sn, s);

    printf("Case %d:\n", test++);

    n = 0;
    if (s[0] == 'b')
    {
      for (int i = 0; i < strlen(sn); ++i)
      {
        n <<= 1;
        n += sn[i] - '0';
      }
      printf("%d dec\n%x hex\n\n", n, n);
    }
    else if (s[0] == 'd')
    {
      sscanf(sn, "%d", &n);
      printf("%x hex\n", n);

      int i;
      for (i = 0; n > 0; ++i)
      {
        sn[i] = n % 2;
        n >>= 1;
      }
      for (int j = i - 1; j >= 0; --j)
        printf("%d", sn[j]);
      printf(" bin\n\n");
    }
    else
    {
      sscanf(sn, "%x", &n);
      printf("%d dec\n", n);

      int i;
      for (i = 0; n > 0; ++i)
      {
        sn[i] = n % 2;
        n >>= 1;
      }
      for (int j = i - 1; j >= 0; --j)
        printf("%d", sn[j]);
      printf(" bin\n\n");
    }
  }

  return 0;
}
