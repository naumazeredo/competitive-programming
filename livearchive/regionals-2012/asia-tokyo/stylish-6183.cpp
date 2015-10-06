#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 20;
const int N = 22;
char sp[N][4*N], sq[N][4*N];
int cnt[N][3][2][2], cp[N];

void add(int i, int pq, char c) {
  if (c == '(') cnt[i][0][0][pq]++;
  if (c == ')') cnt[i][0][1][pq]++;
  if (c == '{') cnt[i][1][0][pq]++;
  if (c == '}') cnt[i][1][1][pq]++;
  if (c == '[') cnt[i][2][0][pq]++;
  if (c == ']') cnt[i][2][1][pq]++;
}

int main() {
  int p, q;
  while (scanf("%d%d", &p, &q) != EOF && p && q) {
    memset(cnt, 0, sizeof(cnt));
    memset(cp, 0, sizeof(cp));

    for (int i = 1; i <= p; ++i) {
      scanf("%s", sp[i]);
      for (int j=0; j<3; ++j) for (int k=0; k<2; ++k) cnt[i][j][k][0]=cnt[i-1][j][k][0];
      for (int j=0; sp[i][j]; ++j) add(i, 0, sp[i][j]);
      for (int j=0; sp[i][j]=='.'; ++j) cp[i]++;
    }
    for (int i = 1; i <= q; ++i) {
      scanf("%s", sq[i]);
      for (int j=0; j<3; ++j) for (int k=0; k<2; ++k) cnt[i][j][k][1]=cnt[i-1][j][k][1];
      for (int j=0; sq[i][j]; ++j) add(i, 1, sq[i][j]);
    }

    vector<iii> pos;
    vector<int> ans;
    for (int r=1; r<=MAX; ++r) for (int c=1; c<=MAX; ++c) for (int s=1; s<=MAX; ++s) {
      int ok = 1;
      for (int i=1; i<=p; ++i) {
        int t = r * (cnt[i-1][0][0][0] - cnt[i-1][0][1][0]) +
                c * (cnt[i-1][1][0][0] - cnt[i-1][1][1][0]) +
                s * (cnt[i-1][2][0][0] - cnt[i-1][2][1][0]);
        if (t != cp[i]) {
          ok = 0;
          break;
        }
      }

      if (ok) pos.push_back(iii(r, ii(c, s)));
    }

    for (int i = 1; i <= q; ++i) {
      int v = -1;
      for (int j=0; j < (int)pos.size(); ++j) {
        int r = pos[j].first;
        int c = pos[j].second.first;
        int s = pos[j].second.second;
        int t = r * (cnt[i-1][0][0][1] - cnt[i-1][0][1][1]) +
                c * (cnt[i-1][1][0][1] - cnt[i-1][1][1][1]) +
                s * (cnt[i-1][2][0][1] - cnt[i-1][2][1][1]);
        if (v < 0) v = t;
        else if (v != t) {
          v = -1;
          break;
        }
      }

      ans.push_back(v);
    }

    printf("%d", ans[0]);
    for (int i = 1; i < (int)ans.size(); ++i)
      printf(" %d", ans[i]);
    printf("\n");
  }

  return 0;
}
