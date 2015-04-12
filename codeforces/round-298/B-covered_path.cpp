#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> f, g;

int main()
{
  int v1, v2, t, d;
  scanf("%d%d%d%d", &v1, &v2, &t, &d);

  int a = v1,
      b = v2;
  for (int i = 0; i < t; ++i)
  {
    f.push_back(a);
    a += d;

    g.push_back(b);
    b += d;
  }

  int tot = 0;
  for (int i = 0; i < t; ++i)
  {
    if (f[i] < g[t - i - 1])
      tot += f[i];
    else
      tot += g[t - i - 1];
  }

  printf("%d\n", tot);

  return 0;
}
