#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct sweet
{
  int used, t, h, m;
};

sweet ss[2000];

int main()
{
  int n, x;
  scanf("%d%d", &n, &x);

  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d%d", &ss[i].t, &ss[i].h, &ss[i].m);
    ss[i].used = 0;
  }

  sort(ss, ss + n, [] (sweet a, sweet b) { return a.m > b.m; });

  int i = 0, cnt1 = 0, cnt2 = 0, t = 0;
  int ix = x;
  while (i != n)
  {
    for (i = 0; i < n; ++i)
    {
      if (!ss[i].used && ss[i].h <= ix && ss[i].t != t)
      {
        ss[i].used = 1;
        ix += ss[i].m;
        t = ss[i].t;
        cnt1++;
        i = 0;
        break;
      }
    }
  }

  for (int i = 0; i < n; ++i)
    ss[i].used = 0;

  ix = x;
  t = 1;
  i = 0;
  while (i != n)
  {
    for (i = 0; i < n; ++i)
    {
      if (!ss[i].used && ss[i].h <= ix && ss[i].t != t)
      {
        ss[i].used = 1;
        ix += ss[i].m;
        t = ss[i].t;
        cnt2++;
        i = 0;
        break;
      }
    }
  }

  printf("%d\n", max(cnt1, cnt2));

  return 0;
}
