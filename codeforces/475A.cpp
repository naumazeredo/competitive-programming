#include <bits/stdc++.h>

char c[] = {'#', 'O'};
int n, a;

int main() {
  scanf("%d", &n);

  a = 0;
  if (n>0) a = (n-1 - (n>2))/3 + 1;
  n -= a;
  printf("+------------------------+\n|");
  for (int i = 0; i < 11; ++i) printf("%c.", c[a>i]);

  a = 0;
  if (n>0) a = (n-1 - (n>1))/2 + 1;
  n -= a;
  printf("|D|)\n|");
  for (int i = 0; i < 11; ++i) printf("%c.", c[a>i]);

  a = n>0;
  n -= a;
  printf("|.|\n|%c.......................|\n|", c[a]);

  a = n;
  for (int i = 0; i < 11; ++i) printf("%c.", c[a>i]);
  printf("|.|)\n");
  printf("+------------------------+\n");

  return 0;
}
