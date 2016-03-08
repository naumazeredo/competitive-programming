#include <bits/stdc++.h>
using namespace std;

// Não dá para simular todos os movimentos por causa
// dos limites do problema (para simular ir do começo
// ao fim começando em um ponto você precisa fazer n
// movimentos, para fazer cada movimento você precisa
// mover k aranhas. Só isso já passa no tempo, pois
// k <= m(n-1) => n*k = n*m*(n-1) <= 8*10^9. Ainda teria
// que simular para as m colunas...

// A ideia é que dada a posição de uma aranha e a direção
// você sabe em qual coluna ela vai coincidir com o movimento.
// obs: x e y são a posição inicial da aranha.
// Direção: D -> nunca é possível encontrar essa
//          R -> só vai coincidir com a coluna i se i>x e i-x == y
//          L -> só vai coincidir com a coluna i se x>i e x-i == y
//          U -> só vai encontrar quem vem descendo da mesma coluna
//               se y for par, começando no zero (os dois fazem
//               movimentos simultaneos, quando y é par os dois
//               cruzam mas nunca param no mesmo quadrado)

int n, m, k;

int col[3000]; // armazena quantas aranhas encontram cada coluna

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int y = 0; y < n; ++y) for (int x = 0; x < m; ++x) { // cuidado com a ordem dos for!
    char c;
    scanf(" %c", &c);
    if (c == 'U') col[x] += !(y%2); // jeito rápido de somar 1 se y é par (para ímpar basta retirar o !)
    if (c == 'R' and x+y < m)  col[x+y]++;
    if (c == 'L' and x-y >= 0) col[x-y]++; // tem que verificar se x-y >= 0 para poder usar como índice do vetor
  }

  for (int i = 0; i < m; ++i) printf("%d ", col[i]);
  printf("\n");
  return 0;
}
