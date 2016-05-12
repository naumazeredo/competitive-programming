#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n;
char m[5][5];
int c[5][5];
int t;

void bt(int x, int cnt) {
  for (int i = x; i < n*n; ++i) {
    if (m[i/n][i%n] == 'X') continue;
    if (c[i/n][i%n]) continue;

    for (int j = (i%n)-1; j >= 0 and m[i/n][j]!='X'; --j) c[i/n][j]++;
    for (int j = (i%n)+1; j < n and m[i/n][j]!='X'; ++j) c[i/n][j]++;
    for (int j = (i/n)-1; j >= 0 and m[j][i%n]!='X'; --j) c[j][i%n]++;
    for (int j = (i/n)+1; j < n and m[j][i%n]!='X'; ++j) c[j][i%n]++;
    bt(i+1, cnt+1);
    for (int j = (i%n)-1; j >= 0 and m[i/n][j]!='X'; --j) c[i/n][j]--;
    for (int j = (i%n)+1; j < n and m[i/n][j]!='X'; ++j) c[i/n][j]--;
    for (int j = (i/n)-1; j >= 0 and m[j][i%n]!='X'; --j) c[j][i%n]--;
    for (int j = (i/n)+1; j < n and m[j][i%n]!='X'; ++j) c[j][i%n]--;
  }

  t = max(t, cnt);
}

int main() {
  while (scanf("%d", &n) != EOF and n) {
    for (int i = 0; i < n; ++i) scanf("%s", m[i]);
    memset(c, 0, sizeof(c));
    t = 0;

    bt(0, 0);
    printf("%d\n", t);
  }
  return 0;
}
