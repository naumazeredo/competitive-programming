#include <cstdio>
#include <cstring>

int cmd[200];
char instr[100];

int main()
{
  int t, n, a, p;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i)
  {
    p = 0;

    scanf("%d%*c", &n);
    for (int j = 1; j <= n; ++j)
    {
      fgets(instr, 100, stdin);
      instr[strlen(instr) - 1] = '\0';

      if (strcmp(instr, "LEFT") == 0)
        cmd[j] = 0;
      else if (strcmp(instr, "RIGHT") == 0)
        cmd[j] = 1;
      else
      {
        sscanf(instr, "SAME AS %d", &a);
        cmd[j] = cmd[a];
      }

      if (cmd[j] == 0) p--;
      else             p++;
    }

    printf("%d\n", p);
  }

  return 0;
}
