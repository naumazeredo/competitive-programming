#include <cstdio>
#include <vector>

int main()
{

  while (1)
  {
    int a, c;
    std::vector<int> hs;

    // Input
    scanf("%d %d", &a, &c);

    if (a == 0 && c == 0)
      break;

    for (int i = 0; i < c; ++i)
    {
      int t;
      scanf("%d", &t);
      hs.push_back(a - t);
    }

    // Logic
    int varreduras = 0;

    int h = 0;
    for (int i = 0; i < c; ++i)
    {
      int hi = hs[i];
      if (hi > h)
        varreduras += hi - h;
      h = hi;
    }

    // Output
    printf("%d\n", varreduras);
  }

  return 0;
}
