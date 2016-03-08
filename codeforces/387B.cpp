#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[3005], b[3005];
int u[3005]; // vetor para saber se a questão já foi usada

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

  for (int i = 0; i < n; ++i) {
    int cont = 1;
    for (int j = 0; j < m and cont; ++j)
      if (!u[j] and b[j] >= a[i])
        u[j]=1, cont=0; // dois comandos em uma linha: marca como usado e diz pra parar o loop
    if (cont) break; // se não achou nenhuma questão que satisfaz,
                     // acaba o loop pois todos os elementos seguintes são maiores que esse!
  }

  int res = n; // começa dizendo que precisa de todas as questões
  for (int i = 0; i < m; ++i)
    res -= u[i]; // para cada questão que foi usada, reduz a quantidade que precisa

  printf("%d\n", res);
  return 0;
}
