#include <cstdio>
#include <bitset>
using namespace std;

bitset<32> dir[30];

int main()
{
  int t, m, d, c, key;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i)
  {
    scanf("%d %d", &m, &d);

    for (int j = 0; j < d; ++j)
    {
      dir[j] = bitset<32>();
      scanf("%d", &c);
      for (int k = 0; k < c; ++k)
      {
        scanf("%d", &key);
        dir[j].set(key);
      }
    }

    // Complete search
    int mindirs = 9999;
    int numsets = (1 << d);
    for (int j = 0; j < numsets; ++j)
    {
      bitset<20> s (j);
      bitset<32> keys;
      for (size_t k = 0; k < s.size(); ++k)
        if (s.test(k))
          keys |= dir[k];

      if (keys.count() >= m && mindirs > s.count())
        mindirs = s.count();
    }

    if (mindirs < 100)
      printf("%d\n", mindirs);
    else
      printf("Desastre!\n");
  }

  return 0;
}
