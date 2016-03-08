#include <bits/stdc++.h>
using namespace std;

char p[100005]; // Como o número é muito grande, basta armazenar o número em uma sequencia de chars

int cmp(int b0, int l0, int b1, int l1) {
  if (l0 != l1) return l0 > l1;
  for (int i = 0; i < l0; ++i)
    if (p[b0+i] != p[b1+i])
      return p[b0+i] > p[b1+i];
  return 1;
}

int main() {
  scanf("%s", p);

  int l=0;
  int res = 0;
  for (int i = 0; p[i];) { // jeito rápido de andar em uma string: basta colocar a condição como p[i] (dúvida pq? me perguta!)
    int b0=i;
    while (p[++i] and p[i] == '0') ;
    int l0=i-b0;

    if (!cmp(0, l, b0, l0)) res = 1;
    else res++;
    l=i;
  }

  printf("%d\n", res);
  return 0;
}
