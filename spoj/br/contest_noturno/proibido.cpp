#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int n;
  std::cin >> n;

  std::vector<int> illegals;
  for (int i = 0; i < n; ++i)
    illegals.resize(illegals.size() + 1),
    std::cin >> illegals[illegals.size() -1];

  std::sort(illegals.begin(), illegals.end());

  int c;
  while ((std::cin >> c) && c)
  {
    //if (std::find(illegals.begin(), illegals.end(), c) != illegals.end())
    if (std::binary_search(illegals.begin(), illegals.end(), c))
      std::cout << "sim" << std::endl;
    else
      std::cout << "nao" << std::endl;
  }

  return 0;
}
