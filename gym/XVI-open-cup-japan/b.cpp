#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;
int x[3005], y[3005];
char d[3005];
map<int, int> xm, ym;

int g[3005][3005];

int pleft[3005], pright[3005], pup[3005], pdown[3005];

void rm(int cur) {
  pleft[pright[cur]] = pleft[cur];
  pright[pleft[cur]] = pright[cur];
  pup[pdown[cur]] = pup[cur];
  pdown[pup[cur]] = pdown[cur];
  if (pleft[cur] != -1) pright[pleft[cur]] = pright[cur];
  if (pright[cur] != -1) pleft[pright[cur]] = pleft[cur];
  if (pup[cur] != -1) pdown[pup[cur]] = pdown[cur];
  if (pdown[cur] != -1) pup[pdown[cur]] = pup[cur];
}

void in(int cur) {
  pleft[pright[cur]] = cur;
  pright[pleft[cur]] = cur;
  pup[pdown[cur]] = cur;
  pdown[pup[cur]] = cur;
  if (pleft[cur] != -1) pright[pleft[cur]] = cur;
  if (pright[cur] != -1) pleft[pright[cur]] = cur;
  if (pup[cur] != -1) pdown[pup[cur]] = cur;
  if (pdown[cur] != -1) pup[pdown[cur]] = cur;
}

int main() {
  memset(g, -1, sizeof(g));

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d %c", &x[i], &y[i], &d[i]);
  for (int i = 0; i < n; ++i) xm[x[i]]=0, ym[y[i]]=0;

  int i=0;
  for (map<int, int>::iterator it = xm.begin(); it != xm.end(); ++it) it->second = i++;
  i=0;
  for (map<int, int>::iterator it = ym.begin(); it != ym.end(); ++it) it->second = i++;
  for (int i = 0; i < n; ++i) g[ym[y[i]]][xm[x[i]]] = i;
  for (int i = 0; i < n; ++i) pleft[i] = pright[i] = pup[i] = pdown[i] = -1;

  for (int i = 0; i < n; ++i) {
    int px = xm[x[i]], py = ym[y[i]];
    for (int j = px+1; j < n;  ++j) if (g[py][j]>=0) { pright[i] = g[py][j]; break; }
    for (int j = px-1; j >= 0; --j) if (g[py][j]>=0) { pleft[i] = g[py][j]; break; }
    for (int j = py+1; j < n;  ++j) if (g[j][px]>=0) { pdown[i] = g[j][px]; break; }
    for (int j = py-1; j >= 0; --j) if (g[j][px]>=0) { pup[i] = g[j][px]; break; }
  }

  int ma = 0;
  for (int i = 0; i < n; ++i) {
    int cur = i, int value = 1;
    vector<int> order;
    while (1) {
      order.push_back(cur);
      if (d[cur] == '>' && pright[cur] == -1) break;
      if (d[cur] == '<' && pleft[cur] == -1) break;
      if (d[cur] == 'v' && pdown[cur] == -1) break;
      if (d[cur] == '^' && pup[cur] == -1) break;
      rm(cur);

      if (d[cur] == '>') cur = pright[cur];
      if (d[cur] == '<') cur = pleft[cur];
      if (d[cur] == 'v') cur = pdown[cur];
      if (d[cur] == '^') cur = pup[cur];
      value++;
    }
    // undo
    for (int j = 0; j < order.size(); ++j) {
      cur = order[j];
      if (d[cur] == '>') in(cur);
      else if (d[cur] == '<') in(cur);
      else if (d[cur] == 'v') in(cur);
      else if (d[cur] == '^') in(cur);
    }

    ma = max(ma, value);
  }

  printf("%d\n", ma);

  return 0;
}
