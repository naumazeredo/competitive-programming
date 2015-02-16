#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <inttypes.h>

struct Node
{
  Node() {}
  Node(uint64_t ne, uint64_t np, uint64_t nn) :
      e(ne), p(np), n(nn)
  {}

  uint64_t e, p, n;
};

int main()
{
  uint64_t e, p, n;
  std::map<uint64_t, Node> lista;
  std::map<uint64_t, bool> observado;

  uint64_t f, l;
  while (std::cin >> std::hex >> e >> std::hex >> p >> std::hex >> n)
  {
    if (lista.empty())
      f = e;
    else if (lista.size() == 1)
      l = e;
    lista[e] = Node(e, p, n);
    observado[e] = false;
  }

  /*
  std::cout << std::endl << "<lista>" << std::endl;
  for(std::map<uint64_t, Node>::iterator v = lista.begin(); v != lista.end(); ++v)
    std::cout << v->second.e << ": " <<
                 v->second.p << " " <<
                 v->second.n << std::endl;
  */

  bool sana = false;
  uint64_t c = f;
  while (true)
  {
    if (!observado[c])
      observado[c] = true;
    else
      break;

    if (lista[c].n != 0)
      if (lista[lista[c].n].p != c)
        break;

    c = lista[c].n;
  }

  if (observado[lista[f].e] && observado[lista[l].e])
    sana = true;

  if (sana)
    printf("sana\n");
  else
    printf("insana\n");

  return 0;
}
