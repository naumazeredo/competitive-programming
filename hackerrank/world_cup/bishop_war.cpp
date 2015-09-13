#include <bits/stdc++.h>
using namespace std;

int n, m;
char t[10][10];
int a[10][10];

int c = 0;

void nbishop(int r) {
  for (int i = 0; i < m; ++i) {
    if (t[r][i] == '*') continue;
    if (a[r][i] == 0) {
      if (r == n-1) {
        c++;
        continue;
      }

      for (int j = 1;r+j<n && i-j>=0 && t[r+j][i-j]=='.';++j) a[r+j][i-j]++;
      for (int j = 1;r+j<n && i+j<m  && t[r+j][i+j]=='.';++j) a[r+j][i+j]++;
      nbishop(r+1);
      for (int j = 1;r+j<n && i-j>=0 && t[r+j][i-j]=='.';++j) a[r+j][i-j]--;
      for (int j = 1;r+j<n && i+j<m  && t[r+j][i+j]=='.';++j) a[r+j][i+j]--;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> t[i][j];
      a[i][j] = 0;
    }
    cin.ignore(1);
  }

  nbishop(0);
  cout << c << endl;

  return 0;
}
