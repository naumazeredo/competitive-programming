#include <bits/stdc++.h>
using namespace std;

int n;
int m=0, x=0, l=-1;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a >= l) {
      x++;
      m = max(m, x);
    } else {
      x = 1;
    }

    l = a;
  }

  cout << m << endl;

  return 0;
}
