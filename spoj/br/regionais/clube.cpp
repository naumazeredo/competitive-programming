#include <cstdio>
#include <algorithm>
using namespace std;

int xs[2000000];

int main()
{
  int m, n, l, k;
  while (scanf("%d %d", &m, &n) != EOF && m)
  {
    scanf("%d", &l);
    scanf("%d", &k);

    for (int i = 0; i < k; ++i)
      scanf("%d", &xs[i]);

    sort(xs, xs + k);

    int minn = k + 1;
    int linhas = 0;
    bool ok = false;

    if ((m * 100) % l == 0)
    {
      int maxlinhas = (m * 100) / l;
      int cnt = 0;
      int i = k - 1,
          j = 0;
      while (j <= i && linhas < maxlinhas)
      {
        if (xs[i] > n)
        {
          i--;
        }
        else if (xs[i] == n)
        {
          cnt++;
          linhas++;
          i--;
        }
        else
        {
          if (j == i)
          {
            break;
          }

          int sum = xs[i] + xs[j];
          if (sum < n)
          {
            j++;
          }
          else if (sum == n)
          {
            cnt += 2;
            linhas++;
            i--;
            j++;
          }
          else
          {
            i--;
          }
        }
      }

      if (linhas == maxlinhas && minn > cnt)
      {
        minn = cnt;
        ok = true;
      }
    }

    linhas = 0;

    if ((n * 100) % l == 0)
    {
      int maxlinhas = (n * 100) / l;
      int cnt = 0;
      int i = k - 1,
          j = 0;
      while (j <= i && linhas < maxlinhas)
      {
        if (xs[i] > m)
        {
          i--;
        }
        else if (xs[i] == m)
        {
          cnt++;
          linhas++;
          i--;
        }
        else
        {
          if (j == i)
          {
            break;
          }

          int sum = xs[i] + xs[j];
          if (sum < m)
          {
            j++;
          }
          else if (sum == m)
          {
            cnt += 2;
            linhas++;
            i--;
            j++;
          }
          else
          {
            i--;
          }
        }
      }

      if (linhas == maxlinhas && minn > cnt)
      {
        minn = cnt;
        ok = true;
      }
    }

    if (ok)
      printf("%d\n", minn);
    else
      printf("impossivel\n");
  }

  return 0;
}
