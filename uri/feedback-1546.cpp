#include <cstdio>

int main()
{
  int n, k, f;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &k);
    for (int j = 0; j < k; ++j)
    {
      scanf("%d", &f);
      if (f == 1) printf("Rolien\n");
      else if (f == 2) printf("Naej\n");
      else if (f == 3) printf("Elehcim\n");
      else if (f == 4) printf("Odranoel\n");
    }
  }

  return 0;
}
