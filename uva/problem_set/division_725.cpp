#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool diffDigits(int a, int b)
{
  vector<int> digs;
  for (int i = 0; i < 5; ++i)
  {
    digs.push_back(a % 10);
    a /= 10;
  }

  for (int i = 0; i < 5; ++i)
  {
    digs.push_back(b % 10);
    b /= 10;
  }

  sort(digs.begin(), digs.end());
  for (unsigned int i = 1; i < digs.size(); ++i)
    if (digs[i - 1] == digs[i])
      return false;

  return true;
}

int main()
{
  int n;
  bool b = false;
  while ((scanf("%d", &n) != EOF) && n)
  {
    if (!b)
      b = true;
    else
      printf("\n");

    bool found = false;
    int den = 1234;
    while (den <= 98765)
    {
      int num = den * n;
      if (num >= 100000)
        break;

      if (diffDigits(num, den))
      {
        found = true;
        printf("%05d / %05d = %d\n", num, den, n);
      }

      den++;
    }

    if (!found)
      printf("There are no solutions for %d.\n", n);
  }

  return 0;
}
