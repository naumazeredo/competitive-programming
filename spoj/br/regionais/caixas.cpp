#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, p, maxesq, maxdir, x, y;

  while (cin >> n >> p && n)
  {
    vector<int> hs;
    hs.resize(p);

    for (int i = 0; i < p; ++i)
    {
      int h;
      cin >> h;
      hs[i] = h;
      for (int j = 0; j < h; ++j)
      {
        int cx;
        cin >> cx;
        if (cx == 1)
          x = i, y = j;
      }
    }

    maxesq = 0;
    for (int i = x; i >= 0; --i)
    {
      int c = hs[i] - y;
      if (c <= 0)
        break;
      maxesq += c;
    }

    maxdir = 0;
    for (int i = x; i < p; ++i)
    {
      int c = hs[i] - y;
      if (c <= 0)
        break;
      maxdir += c;
    }

    cout << min(maxesq, maxdir) - 1 << endl;
  }

  return 0;
}
