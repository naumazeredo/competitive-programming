#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> m;
vector<int> v;

int gcd(int a, int b) {
  return b?gcd(b, a%b):a;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n*n; ++i) {
    int a;
    scanf("%d", &a);
    if (m.find(a) != m.end()) {
      m[a]++;
    } else {
      m[a]=1;
    }
  }

  while ((int)v.size() < n) {
    map<int, int>::iterator it = m.end();
    it--;
    int k = (*it).first;
    m[(*it).first]--;
    if (!m[(*it).first]) m.erase(it);

    for (int i = 0; i < (int)v.size(); ++i) {
      it = m.find(gcd(v[i], k));
      m[(*it).first]-=2;
      if (!m[(*it).first]) m.erase(it);
    }

    v.push_back(k);
  }

  for (int i = 0; i < n; ++i) printf("%d ", v[i]);
  printf("\n");

  return 0;
}
