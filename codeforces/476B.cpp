#include <bits/stdc++.h>

int totalbal, bal, n;
char c;

int cs(int d, int b) {
  if (d == n) return b == totalbal;
  return cs(d+1, b+1) + cs(d+1, b-1);
}

int main() {
  while (~scanf("%c", &c) and c != '\n') totalbal += (c=='+' ? 1 : -1);
  while (~scanf("%c", &c) and c != '\n') bal += (c=='+' ? 1 : (c=='-'? -1 : 0)), n += (c=='?');

  printf("%.10f\n", cs(0, bal) / (double)(1<<n));
  return 0;
}
