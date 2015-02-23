#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while (cin >> n && n)
  {
    vector<int> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i)
    {
      int x;
      cin >> x;
      a.push_back(x);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
      while (a[i] != i + 1 && ++cnt)
        swap(a[i], a[a[i] - 1]);
    }

    cout << (cnt % 2 == 1 ? "Marcelo" : "Carlos") << endl;
  }

  return 0;
}
