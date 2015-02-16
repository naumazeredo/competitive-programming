#include <cstdio>
#include <algorithm>

int main()
{
  int K;
  while (scanf("%d", &K) && K)
  {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < K; ++i)
    {
      int X, Y;
      scanf("%d %d", &X, &Y);
      if (X != N && Y != M)
      {
        if (Y > M)
          printf("N");
        else
          printf("S");

        if (X > N)
          printf("E\n");
        else
          printf("O\n");

      }
      else
        printf("divisa\n");
    }
  }

  return 0;
}
