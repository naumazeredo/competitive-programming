#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int r[10];
vector< vector<int> > v;

void cs(int x, vector<int> res) {
  for (int i = 0; i < 8; ++i) {
    int no=1;
    for (int j = 0; j < x && no; ++j)
      if (abs(x-j)==abs(i-r[j]) or r[j] == i) no=0;
    if (!no) continue;

    r[x] = i;
    res.push_back(i);
    if (x == 7) v.push_back(res);
    else cs(x+1, res);
    res.pop_back();
  }
}

int main() {
  cs(0, vector<int>());
  int cas = 1;
  while (1) {
    int ok = 1;
    for (int i = 0; i < 8 and ok; ++i) if (scanf("%d", &r[i]) == EOF) ok=0;
    if (!ok) break;

    int mi = 10;
    for (int i = 0; i < v.size(); ++i) {
      int cnt = 0;
      for (int j = 0; j < 8; ++j) if (r[j]-1 != v[i][j]) cnt++;
      mi = min(cnt, mi);
    }

    printf("Case %d: %d\n", cas++, mi);
  }
  return 0;
}
