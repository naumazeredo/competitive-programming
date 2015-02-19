#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int l, c, r1, r2;
  while (cin >> l >> c >> r1 >> r2 && l)
  {
    float menor = min(l, c),
          maior = max(l, c);

    int d = menor - r1 - r2;
    float x = r1 + r2 + sqrt((r1 + r2) * (r1 + r2) - d * d);

    if (2 * r1 > menor ||
        2 * r2 > menor ||
        x > maior)
      cout << 'N' << endl;
    else
      cout << 'S' << endl;
  }
}
