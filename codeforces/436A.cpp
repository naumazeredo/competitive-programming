#include <bits/stdc++.h>
using namespace std;

int n, x, ct, cx, total;
int t[3000], h[3000], m[3000];
int v[3000];

int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; ++i) scanf("%d%d%d", &t[i], &h[i], &m[i]);

  // Começa comendo o tipo 0
  cx = x;
  ct = 0;
  total = 0;
  while (1) {
    // Procura o doce com maior massa que pode ser comido (estratégia gulosa)
    int ma = 0, ind = -1;
    for (int i = 0; i < n; ++i)
      if (!v[i] and       // não foi comido ainda
          t[i] == ct and    // tipo igual ao que queremos
          h[i] <= cx and    // altura alcançável
          m[i] > ma)        // massa maior que encontramos até agora
        ma = m[i], ind = i; // !dois comandos em uma linha!

    if (ind < 0) break;     // não achou nenhuma doce que pudesse comer

    total++;
    cx += ma;   // aumenta o pulo
    v[ind]=1;   // marca que comeu o doce
    ct = 1-ct;  // !jeito rápido de alternar entre 0 e 1
  }

  int res = total; // armazena o resultado começando no tipo 0

  // marca todos os doces como não comidos
  for (int i = 0; i < n; ++i) v[i]=0; // podia usar: memset(v, 0, sizeof(v));

  // comendo o tipo 1
  cx = x;
  ct = 1;
  total = 0;
  while (1) {
    int ma = 0, ind = -1;
    for (int i = 0; i < n; ++i)
      if (!v[i] and t[i] == ct and h[i] <= cx and m[i] > ma)
        ma = m[i], ind = i;
    if (ind < 0) break;

    total++;
    cx += ma;
    v[ind]=1;
    ct = 1-ct;
  }

  res = max(res, total); // Pega o máximo entre 

  printf("%d\n", res);
  return 0;
}
