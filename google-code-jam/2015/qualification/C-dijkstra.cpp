#include <cstdio>
#include <set>
using namespace std;

int seek;
int cur, per;
set<int> f;
char s[20000];

void mult(char b)
{
  bool pos = cur > 0;
  cur = (pos ? cur : -cur);

  if (cur == 1)
    cur = b - 'i' + 2;
  else if (cur == 2)
  {
    if (b == 'i')
      cur = -1;
    else if (b == 'j')
      cur = 4;
    else if (b == 'k')
      cur = -3;
  }
  else if (cur == 3)
  {
    if (b == 'i')
      cur = -4;
    else if (b == 'j')
      cur = -1;
    else if (b == 'k')
      cur = 2;
  }
  else if (cur == 4)
  {
    if (b == 'i')
      cur = 3;
    else if (b == 'j')
      cur = -2;
    else if (b == 'k')
      cur = -1;
  }

  cur = cur * (pos ? 1 : -1);
}

int main()
{
  int t;
  scanf("%d", &t);

  int l;
  long long x;
  for (int i = 1; i <= t; ++i)
  {
    printf("Case #%d: ", i);

    cur = 1;
    scanf("%d%lld", &l, &x);
    for (int j = 0; j < l; ++j)
    {
      scanf(" %c", &s[j]);
      mult(s[j]);
    }
    per = cur;

    f.clear();
    seek = 2;
    cur = 1;

    long long si = x * l;
    long long p;
    for (p = 0; p < si; ++p)
    {
      if (p % l == 0)
      {
        if (seek > 4)
          break;

        if (f.find(cur) != f.end())
          break; // Repeating loop
        f.insert(cur);
      }

      mult(s[p % l]);

      if (seek <= 4 && cur == seek)
      {
        seek++;
        cur = 1;
        f.clear();
      }
    }

    if (seek > 4)
    {
      int k = ((l * x - p) / l) % 4;
      int p2;
      bool pos = (per > 0);
      for (int j = 0; j < k; ++j)
      {
        p2 = (pos ? per : -per);
        mult(p2 + 'i' - 2);
        cur = cur * (pos ? 1 : -1);
      }

      if (cur == 1)
        printf("YES\n");
      else
        printf("NO\n");
    }
    else
      printf("NO\n");
  }

  return 0;
}
