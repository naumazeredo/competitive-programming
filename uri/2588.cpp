#include <bits/stdc++.h>
using namespace std;

char s[1005];
int cnt[300];

int main() {
  while (scanf("%s", s) != EOF) {
    memset(cnt, 0, sizeof(cnt));
    int n = strlen(s);

    for (int i = 0; i < n; i++)
      cnt[s[i]]++;

    int impar = 0;
    for (int i = 0; i < 300; i++)
      if (cnt[i] % 2 == 1) impar++;

    if (impar <= 1) printf("0\n");
    else printf("%d\n", impar - 1);
  }
  return 0;
}
