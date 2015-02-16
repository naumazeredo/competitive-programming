#include <cstdio>
#include <cstdlib>
#include <iostream>

int main()
{
  //int d, n;
  //while (scanf("%d%d", &d, &n) && (d || n))
  char d;
  std::string n;
  while (std::cin >> d >> n && d != '0')
  {
    std::string number;

    for (int i = 0; i < n.size(); ++i)
      if (n[i] != d)
        number.push_back(n[i]);

    while (number.size() > 0)
    {
      if (number[0] == '0')
        number.erase(number.begin());
      else
        break;
    }
    if (number.size() == 0)
      number.push_back('0');

    printf("%s\n", number.c_str());
  }

  return 0;
}
