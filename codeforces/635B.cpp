#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, a[3];
char c;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %c", &c);
    if (c == 'B') a[0]++;
    if (c == 'G') a[1]++;
    if (c == 'R') a[2]++;
  }

       if (a[0] and !a[1] and !a[2]) printf("B\n");
  else if (!a[0] and a[1] and !a[2]) printf("G\n");
  else if (!a[0] and !a[1] and a[2]) printf("R\n");

  else if (a[0]==1 and a[1]==1 and a[2]==0) printf("R\n");
  else if (a[0]==1 and a[1]==0 and a[2]==1) printf("G\n");
  else if (a[0]==0 and a[1]==1 and a[2]==1) printf("B\n");

  else if (a[0]>=2 and a[1]==1 and a[2]==0) printf("GR\n");
  else if (a[0]>=2 and a[1]==0 and a[2]==1) printf("GR\n");

  else if (a[0]==1 and a[1]>=2 and a[2]==0) printf("BR\n");
  else if (a[0]==0 and a[1]>=2 and a[2]==1) printf("BR\n");

  else if (a[0]==1 and a[1]==0 and a[2]>=2) printf("BG\n");
  else if (a[0]==0 and a[1]==1 and a[2]>=2) printf("BG\n");

  else printf("BGR\n");

  return 0;
}
