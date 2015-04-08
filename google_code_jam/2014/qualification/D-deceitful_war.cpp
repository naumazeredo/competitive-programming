#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<float, int> pfi;

vector<pfi> p;
bool used[2000];

int main()
{
  int t;
  scanf("%d", &t);

  float v;
  int n;
  for (int i = 1; i <= t; ++i)
  {
    printf("Case #%d: ", i);
    p.clear();
    memset(used, 0, sizeof(used));

    scanf("%d", &n);
    for (int j = 0; j < n; ++j)
    {
      scanf("%f", &v);
      p.push_back(make_pair(v, 1));
    }
    for (int j = 0; j < n; ++j)
    {
      scanf("%f", &v);
      p.push_back(make_pair(v, -1));
    }

    //sort(p.begin(), p.end(), greater<pfi>());
    sort(p.begin(), p.end());
    /*
    for (int j = 0; j < (int)p.size(); ++j)
      printf("%d ", p[j].second);
    printf("\n");
    */

    int c = 0, w = 0, d = 0;
    for (int j = (int)p.size() - 1; j >= 0; --j)
    {
      c += p[j].second;
      w = max(w, c);
    }

    for (int j = 0; j < (int)p.size(); ++j)
    {
      if (!used[j] && p[j].second > 0)
      {
        used[j] = true;
        for (int k = (int)p.size(); k >= 0; --k)
        {
          if (p[k].second < 0 && !used[k] && j > k)
          {
            d++;
            used[k] = true;
            break;
            //printf("jk: %d %d\n", j, k);
          }
        }
      }
    }

    printf("%d %d\n",d, w);
  }

  return 0;
}
