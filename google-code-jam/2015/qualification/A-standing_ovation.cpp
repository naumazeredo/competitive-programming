#include <cstdio>

int main()
{
  int t;
  scanf("%d", &t);

  int sum, acc;
  int s, c;
  for (int i = 1; i <= t; ++i)
  {
    printf("Case #%d: ", i);

    sum = 0;
    acc = 0;

    scanf("%d", &s);
    for (int j = 0; j < s + 1; ++j)
    {
      scanf("%1d", &c);

      if (c > 0 && j > acc)
      {
        sum += j - acc;
        acc = j;
      }
      acc += c;
    }

    printf("%d\n", sum);
  }

  return 0;
}
