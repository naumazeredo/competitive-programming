#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, d;
  while (cin >> n >> d && (n || d))
  {
    vector<int> res;
    res.resize(n);

    int pos = -1;
    int subs = 0;

    for (int i = 0; i < n; ++i)
    {
      char c;
      cin >> c;
      int val = c - '0';

      while (pos != -1 && res[pos] < val && subs < d)
      {
        pos--;
        subs++;
      }
      res[++pos] = val;
    }

    for (int i = 0; i < n - d; ++i)
      cout << res[i];
    cout << endl;
  }
  return 0;
}
