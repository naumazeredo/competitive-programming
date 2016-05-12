#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int t, n;
int a[200005], aux[200005];
ll inv;

void merge(int l, int m, int r) {
  int k = l, i = l, j = m;
  while (i < m and j < r) {
    if (a[i] <= a[j]) aux[k++] = a[i++];
    else aux[k++] = a[j++], inv+=m-i;
  }

  while (i < m) aux[k++] = a[i++];
  while (j < r) aux[k++] = a[j++];

  for (int i = l; i < r; ++i) a[i] = aux[i];
}

void mergesort(int l, int r) {
  if (l >= r-1) return;
  mergesort(l, (l+r)/2);
  mergesort((l+r)/2, r);
  merge(l, (l+r)/2, r);
}

int main() {
  while (scanf("%d", &n) != EOF and n) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    inv = 0;
    mergesort(0, n);
    printf("%s\n", inv%2?"Marcelo":"Carlos");
  }
  return 0;
}
