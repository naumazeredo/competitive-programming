#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int t, y, m;
char o[30], d[30];
char tmp[30];
int dist[1111];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    memset(dist, -1, sizeof(dist));
    int n;
    map<string, int> id;
    vector<pii> adj[1111];

    scanf(" %s %s%d%d", o, d, &y, &m);
    n = 2;
    id[o] = 0;
    id[d] = 1;

    for (int i = 0; i < m; ++i) {
      int a, b, x;
      scanf(" %s", tmp);
      if (id.find(tmp) == id.end()) id[tmp] = n++;
      a = id[tmp];

      scanf(" %s", tmp);
      if (id.find(tmp) == id.end()) id[tmp] = n++;
      b = id[tmp];

      scanf("%d", &x);

      adj[a].pb(mp(b, x));
    }

    priority_queue<pii> pq;
    pq.push(mp(0, id[o]));

    while (!pq.empty()) {
      int udist = -pq.top().st;
      int uid = pq.top().nd;
      pq.pop();

      if (dist[uid] > 0 and dist[uid] < udist) continue;
      dist[uid] = udist;
      for (int i = 0; i < adj[uid].size(); ++i) {
        int vid = adj[uid][i].st;
        int x = adj[uid][i].nd;
        int nex = (udist/x)*x + (udist%x>0)*x;
        if (dist[vid] < 0 or dist[vid] > nex + y)
          dist[vid] = nex + y,
          pq.push(mp(-nex-y, vid));
      }
    }

    printf("Caso #%d: ", tt);
    if (dist[id[d]]>=0) printf("%d anticalmas\n", dist[id[d]]);
    else printf("Destino inalcancavel\n");
  }
  return 0;
}
