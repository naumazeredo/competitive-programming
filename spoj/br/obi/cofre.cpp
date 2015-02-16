#include <iostream>
using namespace std;

int main()
{
  int teste = 1;
  int n;
  while (cin >> n && n != 0)
  {
    cout << "Teste " << teste++ << endl;

    int j, z;
    int diff = 0;
    for (int i = 0; i < n; ++i)
    {
      cin >> j >> z;
      diff += j - z;
      cout << diff << endl;
    }

    cout << endl;
  }

  return 0;
}
