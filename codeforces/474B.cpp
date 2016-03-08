#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int a[100005];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]), a[i] += a[i-1]; // acumula os valores do vetor (prefix sum)

  // Com o vetor em prefix sum de valores positivos temos sempre um vetor ordenado
  // Portanto podemos usar busca binária para encontrar nosso valor

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &q); // Como não vamos precisar dos valores passados, podemos armazenar temporariamente o pedido
    printf("%d\n", lower_bound(a, a+n, q) - a); // Fazemos uma busca binária pelo elemento.
                                                // lower_bound vai fazer uma busca binária (num vetor ordenado)
                                                // e retornar um ponteiro para o primeiro elemento que não é
                                                // menor que o que procuramos
                                                // Me pergunte como isso funciona (ou procure a documentação!)
  }

  return 0;
}
