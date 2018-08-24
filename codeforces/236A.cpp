#include <bits/stdc++.h>
using namespace std;

char s[105];
int c[300];

int main() {
  scanf("%s", s);
  for (int i = 0; s[i]; i++) c[s[i]]=1;
  int cnt = 0;
  for (int i = 0; i < 300; i++) cnt += c[i];
  printf("%s\n", cnt%2 ? "IGNORE HIM!" : "CHAT WITH HER!");
  return 0;
}
