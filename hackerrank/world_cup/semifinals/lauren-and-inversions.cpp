#include <bits/stdc++.h>
using namespace std;

int n;
int v[1000000];
int va[1000000];
int f[1000000];
int b[1000000];
int p[1000000];

void merg(int l, int m, int r) {
  int i = l, j = m;
  int k = l;
  while (i < m && j < r) {
    if (v[i] < v[j]) {
      f[p[v[i]]] += j-m;
      va[k] = v[i], i++, k++;
    } else {
      b[p[v[j]]] += m-i;
      va[k] = v[j], j++, k++;
    }
  }

  if (j == r) {
    for (;i < m; ++i) {
      f[p[v[i]]]+=r-m; va[k] = v[i]; k++;
    }
  }
  else if (i == m) {
    for (;j < r; ++j) {
      va[k] = v[j]; k++;
    }
  }

  for (int x = l; x < r; ++x) {
    v[x] = va[x];
  }
}

void merg_cnt(int l, int r) {
  if (l == r-1)
    return;

  int mid = (l+r)/2;
  merg_cnt(l, mid);
  merg_cnt(mid, r);

  merg(l, mid, r);
}

int main () {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    p[v[i]] = i;
  }
  memset(f, 0, sizeof(f));
  memset(b, 0, sizeof(b));
  memset(va, 0, sizeof(va));

  merg_cnt(0, n);

  int fm = 0;
  int bm = 0;
  for (int i = 1; i < n; ++i) {
    if (f[i] > f[fm]) {
      fm = i;
      bm = i;
    }
    if (b[i] > b[bm]) {
      bm = i;
    }
  }

  if (fm != bm)
    cout << fm+1 << " " << bm+1 << endl;
  else
    cout << "Cool Array" << endl;

  return 0;
}
