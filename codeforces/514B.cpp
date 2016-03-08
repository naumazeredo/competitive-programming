#include <bits/stdc++.h>
using namespace std;

int n, xi, yi; // Não use y0 no nome... Existe uma variável com esse nome na STL já...
int x[2000], y[2000];

int gcd(int a, int b) { return b?gcd(b,a%b):a; } // mdc

int main() {
  scanf("%d%d%d", &n, &xi, &yi);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &x[i], &y[i]), x[i]-=xi, y[i]-=yi; // recebe o input e já subtrai da posição inicial

  // Trataremos todos os elementos para simplificar as contas

  // Como o tiro sai nas duas direções, podemos juntar quadrantes em um só
  // 1o quadrante == 3o quadrante
  // 2o quadrante == 4o quadrante
  for (int i = 0; i < n; ++i)
    if (x[i] < 0) x[i] = -x[i], y[i] = -y[i];

  // Vamos reduzir a fração y/x para calcular mais facilmente se os elementos estão na mesma reta
  for (int i = 0; i < n; ++i) {
    int g = gcd(x[i], abs(y[i]));
    x[i] /= g, y[i] /= g;
  }

  // Além disso temos que tratar os casos x=0, tornando todos iguais (y positivo)
  for (int i = 0; i < n; ++i) if (!x[i]) y[i] = abs(y[i]);

  // A ideia é armazenar as "tangentes" que já atiramos.
  // Quando verificamos outro inimigo, vemos se já atiramos na direção dele,
  // se sim, não precisamos atirar denovo, se não, adicionamos no vetor de
  // "tangentes" e aumentamos um tiro no total
  int total = 0;
  vector<int> xs, ys; // vector<int> é um vetor dinâmico de C++ (procure a referência)
  for (int i = 0; i < n; ++i) {
    int atira = 1;
    for (int j = 0; j < xs.size(); ++j) // a função .size() do vector retorna a qnt de elementos atualmente
      if (xs[j] == x[i] and ys[j] == y[i]) // se já atiramos nessa direção, marcamos atira como 0
        atira = 0;

    if (atira) { // Se vamos atirar
      total++;
      xs.push_back(x[i]); // adiciona a nova tangente nos vetores
      ys.push_back(y[i]);
    }
  }

  printf("%d\n", total);
  return 0;
}
