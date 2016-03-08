#include <bits/stdc++.h>
using namespace std;

int sh, sm,
    h, m;

int main() {
  scanf("%d:%d", &sh, &sm);
  scanf("%d:%d", &h, &m);

  sh = (24+sh-h - (sm<m))%24; // se sm < tm, então vai ter que voltar mais uma hora
  sm = (60+sm-m)%60; // sempre que tirar módulo de subtração lembre de
                      // somar o proprio modulo para não dar negativo

  printf("%02d:%02d\n", sh, sm);
  return 0;
}
