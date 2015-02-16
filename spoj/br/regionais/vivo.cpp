#include <cstdio>
#include <vector>

int main()
{
  int teste = 1;

  while (1)
  {
    int p, r;
    scanf("%d %d", &p, &r);

    if (p == 0)
      break;

    // Cria fila
    std::vector<int> participantes;

    // Recebe a posiçao dos participantes
    for (int i = 0; i < p; ++i)
    {
      int t;
      scanf("%d", &t);
      participantes.push_back(t);
    }

    // Pega cada jogada
    for (int i = 0; i < r; ++i)
    {
      int restante, chefe;
      scanf("%d %d", &restante, &chefe);

      int mortos = 0;
      for (int j = 0; j < restante; ++j)
      {
        int escolha;
        scanf("%d", &escolha);
        if (escolha != chefe)
          participantes.erase(participantes.begin() + j - (mortos++));
      }
    }

    // Imprime o vencedor
    // PS.: Isso nao garante que haja vencedor. O input deve estar coerente
    printf("Teste %d\n%d\n", teste++, participantes.at(0));
  }

  return 0;
}
