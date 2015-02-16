#include <cstdio>

int main()
{
  int h, m, s;
  while(scanf("%d:%d:%d", &h, &m, &s) != EOF)
    printf("%d\n", (23 - h) * 60 * 60 + (59 - m) * 60 + (60 - s));

  return 0;
}
