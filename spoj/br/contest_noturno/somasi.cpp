#include <string>
#include <iostream>

int main()
{
  int n;

  std::cin >> n;

  for (int i = 0; i < n; ++i)
  {
    std::string a, b;
    std::cin >> a >> b;

    char la = a[a.size() - 1],
         lb = b[b.size() - 1];

    int ua, ub;

    if (la == '0' || la == '2' || la == '4' || la == '6' || la == '8') ua = 0;
    else ua = 1;
    if (lb == '0' || lb == '2' || lb == '4' || lb == '6' || lb == '8') ub = 0;
    else ub = 1;

    if (ua == ub)
      std::cout << "Par" << std::endl;
    else
      std::cout << "Impar" << std::endl;
  }

  return 0;
}
