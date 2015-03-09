#include <cstdio>
#include <map>
#include <string>
using namespace std;

#define N 100000

char arrayname[N][20];
map<string, int> ids;
int baseaddr[N];
int sizebytes[N];
int dim[N];
int upperbound[N][20];
int lowerbound[N][20];
int c[N][20];

int main()
{
  int n, r;
  scanf("%d %d", &n, &r);

  for (int i = 0; i < n; ++i)
  {
    scanf("%s %d %d %d", arrayname[i], &baseaddr[i], &sizebytes[i], &dim[i]);
    ids[arrayname[i]] = i;

    for (int j = 1; j <= dim[i]; ++j)
      scanf("%d %d", &lowerbound[i][j], &upperbound[i][j]);
  }

  for (int i = 0; i < n; ++i)
  {
    c[i][dim[i]] = sizebytes[i];
    for (int j = dim[i] - 1; j > 0; --j)
      c[i][j] = c[i][j+1] * (upperbound[i][j+1] - lowerbound[i][j+1] + 1);

    c[i][0] = baseaddr[i];
    for (int j = 1; j <= dim[i]; ++j)
      c[i][0] -= c[i][j] * lowerbound[i][j];
  }

  char buffer[20];
  int index;
  int res = 0;
  for (int i = 0; i < r; ++i)
  {
    scanf("%s", buffer);
    printf("%s[", buffer);
    int id = ids[buffer];

    res = c[id][0];
    for (int j = 1; j <= dim[id]; ++j)
    {
      if (j > 1)
        printf(", ");
      scanf("%d", &index);
      printf("%d", index);
      res += c[id][j] * index;
    }

    printf("] = %d\n", res);
  }

  return 0;
}
