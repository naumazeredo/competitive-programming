#include <cstdio>
#include <cstring>

char s[200], t[200];

void solve(int x) {
  s[x]++;
  if (s[x] > 'z') {
    s[x] = 'a';
    solve(x-1);
  }
}

int main() {
  fgets(s, 200, stdin);
  fgets(t, 200, stdin);
  int l = strlen(s) - 1;
  s[l] = '\0';
  t[l] = '\0';

  solve(l-1);

  if (strcmp(s, t) == 0)
    printf("No such string\n");
  else
    printf("%s\n", s);

  return 0;
}
