#include <bits/stdc++.h>
using namespace std;

char s[6000];

int main() {
  scanf("%s", s);

  int l = strlen(s);
  int res = 0, // resultado da questão
      b = -1;   // posição do 'b' do último "bear" encontrado
  for (int i = 0; i < l-3; ++i) // como vamos usar as 3 próximas letras temos que colocar a condição para não 'estourar' o vetor
    if (s[i] == 'b' and s[i+1] == 'e' and s[i+2] == 'a' and s[i+3] == 'r')
      res += (i-b)*(l-(i+3)), // (i-b) -> posições para iniciar a substring
                              // (l-(i+3)) -> posições para terminar a string
                              // todas essas strings fazem parte da resposta (ver exemplo dado na questão!)
      b = i; // atualiza a posição que achou o último "bear"

  printf("%d\n", res);
  return 0;
}
