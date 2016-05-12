#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
int x, y;
vector<int> adj[200005];

int c[200005];
priority_queue<int> f;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    adj[y].push_back(x);
    c[x]++;
  }

  for (int i = 1; i <= n; ++i) if (!c[i]) f.push(i);

  vector<int> rev;
  while (!f.empty()) {
    int x = f.top(); f.pop();
    for (int i = 0; i < adj[x].size(); ++i) {
      c[adj[x][i]]--;
      if (c[adj[x][i]] == 0) f.push(adj[x][i]);
    }
    rev.push_back(x);
  }

  reverse(rev.begin(), rev.end());
  for (int i = 0; i < n; ++i)
    printf("%d ", rev[i]);
  printf("\n");

  return 0;
}
