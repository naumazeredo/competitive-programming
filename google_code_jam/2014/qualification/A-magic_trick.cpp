#include <cstdio>
#include <set>
using namespace std;

int cs[4][4];
set<int> row;

int main()
{
  int t;
  scanf("%d", &t);

  int l;
  for (int i = 0; i < t; ++i)
  {
    row.clear();

    scanf("%d", &l);
    for (int j = 0; j < 16; ++j)
      scanf("%d", &cs[j/4][j%4]);

    for (int j = 0; j < 4; ++j)
      row.insert(cs[l - 1][j]);

    scanf("%d", &l);
    for (int j = 0; j < 16; ++j)
      scanf("%d", &cs[j/4][j%4]);

    bool ok = true;
    int r = -1;
    for (int j = 0; j < 4; ++j)
    {
      if (row.find(cs[l-1][j]) != row.end())
      {
        if (r > 0)
        {
          ok = false;
          break;
        }
        r = cs[l-1][j];
      }
    }

    printf("Case #%d: ", i + 1);
    if (!ok)
      printf("Bad magician!\n");
    else if (r < 0)
      printf("Volunteer cheated!\n");
    else
      printf("%d\n", r);
  }

  return 0;
}
