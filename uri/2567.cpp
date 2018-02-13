#include <bits/stdc++.h>
using namespace std;

int n, a[2000];

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    //sort(a, a+n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n-1; j++)
        if (a[j] > a[j+1])
          swap(a[j], a[j+1]);

    int ans = 0;
    for (int i = 0; i < n/2; i++)
      ans += a[n-i-1] - a[i];
    printf("%d\n", ans);
  }

  return 0;
}
