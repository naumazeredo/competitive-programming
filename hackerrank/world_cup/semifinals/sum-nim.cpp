#include <bits/stdc++.h>
using namespace std;

int n;
set< vector<int> > as;

int sum = 0;

void cs(const vector<int>& b) {
  as.insert(b);

  int s = b.size();
  int r = b[0];
  for (int i = 1; i < s; ++i)
    r = r^b[i];
  if (!r) {
    sum++;
  }

  vector<int> c;
  c.resize(s-1);

  for (int i = 1; i < s; ++i)
    c[i-1] = b[i];

  for (int i = 0; i < s-1; ++i) {
    if (i > 0) c[i-1] = b[i-1];
    c[i] = b[i] + b[i+1];

    if (as.find(c) == as.end())
      cs(c);
  }
}

int main() {
  scanf("%d", &n);
  vector<int> a;
  a.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  cs(a);
  printf("%d\n", sum);
  return 0;
}
