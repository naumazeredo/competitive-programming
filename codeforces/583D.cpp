#include <bits/stdc++.h>
using namespace std;

int n, t;
int a[105];

map<int, int> m;

int lis(int s)
{
  vector<int> l;
  l.reserve(n);
  for (int i = 0; i < s; ++i)
    l.push_back(1);

  for (int i = 1; i < s; ++i)
    for (int j = 0; j < i; ++j)
      if (a[i%n] >= a[j%n] && l[j] + 1 > l[i])
        l[i] = l[j] + 1;

  int maxi = 0;
  for (int i = 0; i < s; ++i)
    if (l[i] > maxi)
      maxi = l[i];

  return maxi;
}

int main() {
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    m[a[i]]++;
  }

  int mm = 0;
  for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    mm = max(mm, (*it).second);

  int m = lis(t<n ? n*t : n*n);
  if (t>n) m+=mm*(t-n);

  printf("%d\n", m);

  return 0;
}
