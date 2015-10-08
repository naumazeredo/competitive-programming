#include <bits/stdc++.h>
using namespace std;

int a[3][2];

int main() {
  for (int i = 0; i < 3; ++i)
    scanf("%d%d", &a[i][0], &a[i][1]);

  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
    if (a[0][i] == a[1][j] && a[1][j] == a[2][k] && a[0][i] == a[0][1-i]+a[1][1-j]+a[2][1-k]) {
      printf("%d\n", a[0][i]);
      for (int y = 0; y < a[0][1-i]; ++y) {
        for (int x = 0; x < a[0][i]; ++x)
          printf("A");
        printf("\n");
      }
      for (int y = 0; y < a[1][1-j]; ++y) {
        for (int x = 0; x < a[1][j]; ++x)
          printf("B");
        printf("\n");
      }
      for (int y = 0; y < a[2][1-k]; ++y) {
        for (int x = 0; x < a[2][k]; ++x)
          printf("C");
        printf("\n");
      }
      return 0;
    }
  }

  for (int f = 0; f < 3; ++f) {
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
      int s = (f==0)?1:0;
      int t = (f==2)?1:2;
      if (a[f][i] == a[s][j]+a[t][k] && a[s][1-j]==a[t][1-k] &&
          a[f][i] == a[f][1-i]+a[s][1-j]) {
        printf("%d\n", a[f][i]);
        for (int y = 0; y < a[f][1-i]; ++y) {
          for (int x = 0; x < a[f][i]; ++x)
            printf("%c", (f==0?'A':(f==1?'B':'C')));
          printf("\n");
        }
        for (int y = 0; y < a[s][1-j]; ++y) {
          for (int x = 0; x < a[f][i]; ++x)
            if (x < a[s][j]) printf("%c", (s==0?'A':(s==1?'B':'C')));
            else printf("%c", (t==0?'A':(t==1?'B':'C')));
          printf("\n");
        }
        return 0;
      }
    }
  }

  printf("-1\n");

  return 0;
}
