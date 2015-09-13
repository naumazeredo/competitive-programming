#include <bits/stdc++.h>
using namespace std;

int p[10];

int main() {
  for (int i = 0; i < 10; ++i)
    cin >> p[i];

  sort(p, p+10);

  cout << p[9] + p[7] + p[5] << endl;
  return 0;
}
