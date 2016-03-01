#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int n, t;
int a[30];

int ma;
vector<int> res;

void go(int i, int s, vector<int> tracks) {
  if (i == t) {
    if (s > ma) {
      ma = s;
      res = tracks;
    }
    return;
  }

  if (s+a[i] <= n) {
    tracks.push_back(i);
    go(i+1, s+a[i], tracks);
    tracks.pop_back();
  }
  go(i+1, s, tracks);
}

int main() {
  while (scanf("%d%d", &n, &t) != EOF) {
    for (int i = 0; i < t; ++i) scanf("%d", &a[i]);
    ma = 0;
    go(0, 0, vector<int>());

    for (int i = 0; i < res.size(); ++i) printf("%d ", a[res[i]]);
    printf("sum:%d\n", ma);
  }
  return 0;
}
