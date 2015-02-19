#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int a, b;
  while (cin >> a >> b && (a || b))
  {
    vector<int> acards, bcards, res;
    acards.reserve(a);
    bcards.reserve(b);

    for (int i = 0; i < a; ++i)
    {
      int n;
      cin >> n;
      if (acards.size() == 0 || acards.back() != n)
        acards.push_back(n);
    }

    for (int i = 0; i < b; ++i)
    {
      int n;
      cin >> n;
      if (bcards.size() == 0 || bcards.back() != n)
        bcards.push_back(n);
    }

    int acnt = 0;
    for (unsigned int i = 0; i < acards.size(); ++i)
    {
      int val = acards[i];
      if (!binary_search(bcards.begin(), bcards.end(), val))
        acnt++;
    }

    int bcnt = 0;
    for (unsigned int i = 0; i < bcards.size(); ++i)
    {
      int val = bcards[i];
      if (!binary_search(acards.begin(), acards.end(), val))
        bcnt++;
    }

    cout << min(acnt, bcnt) << endl;
  }
}
