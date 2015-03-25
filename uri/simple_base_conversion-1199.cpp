#include <cstdio>
#include <cstring>

char buffer[100000];

int main()
{
  int n;
  while (fgets(buffer, sizeof(buffer), stdin))
  {
    if (strlen(buffer) >= 2 && buffer[0] == '0' && buffer[1] == 'x')
    {
      sscanf(buffer, "%x", &n);
      printf("%d\n", n);
    }
    else
    {
      sscanf(buffer, "%d", &n);
      if (n < 0) break;
      printf("0x%X\n", n);
    }
  }

  return 0;
}
