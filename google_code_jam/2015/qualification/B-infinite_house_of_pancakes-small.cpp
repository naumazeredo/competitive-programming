#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> p;
int t, d, a;

int split()
{
  auto backup = p;
  int v = p.top();
  int t = v;
  for (int i = 2; i <= v / 2; ++i)
  {
    p.pop();
    p.push(i);
    p.push(v - i);

    t = min(t, 1 + split());
    p = backup;
  }

  return t;
}

int main()
{
  scanf("%d", &t);

  for (int i = 1; i <= t; ++i)
  {
    while (!p.empty())
      p.pop();

    printf("Case #%d: ", i);

    scanf("%d", &d);
    for (int j = 0; j < d; ++j)
    {
      scanf("%d", &a);
      p.push(a);
    }

    printf("%d\n", split());
  }

  return 0;
}
