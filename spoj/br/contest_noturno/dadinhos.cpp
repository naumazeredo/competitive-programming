#include <iostream>

int main()
{
  int n, d, c;
  while((std::cin >> n >> d >> c) && (n || d || c))
    std::cout << n * d * c << std::endl;

  return 0;
}
