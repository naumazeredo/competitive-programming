#include <cstdio>

char transformChar(char c)
{
  if (c >= 'A' && c <= 'Z')
    return '2' + (c - 'A' - (c >= 'S' ? 1 : 0) - (c == 'Z' ? 1 : 0)) / 3;
  else
    return c;
}

int main()
{
  char c;
  while (1)
  {
    c = getchar();
    if (c == EOF)
      break;
    printf("%c", transformChar(c));
  }

  return 0;
}
