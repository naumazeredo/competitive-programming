#include <bits/stdc++.h>

char k[3][12] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
char d, s[200];

int main() {
  scanf("%c %s", &d, s);

  for (int i = 0; s[i]; ++i)
    for (int l = 0; l < 3; ++l) for (int c = 0; c < 10; ++c)
      if (k[l][c] == s[i]) printf("%c", k[l][c - (d == 'R' ? 1 : -1)]);
  printf("\n");
  return 0;
}
