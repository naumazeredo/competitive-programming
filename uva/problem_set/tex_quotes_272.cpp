#include <cstdio>

int main()
{
  char c;
  bool b = true;
  while ((c = getchar()) != EOF)
  {
    if (c == '\"')
    {
      if (b)
        printf("``");
      else
        printf("''");
      b = !b;
    }
    else
      printf("%c", c);
  }

  return 0;
}
