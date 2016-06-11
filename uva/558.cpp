#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x),(v),sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e3+5;
int t, n, m, v, a, b, c;
vector<int> adj[N], val[N];
int dist[N];


int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i=0; i<=n; i++) adj[i].clear(), val[i].clear();
    for(int i=0; i<m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      adj[a].pb(b);
      val[a].pb(c);
    }

    cl(dist,63);
    dist[0]=0;

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        for(int k=0; k<adj[j].size(); k++)
          v=adj[j][k], c=val[j][k],
          dist[v]=min(dist[v], dist[j]+c);

    int ok=0;
    for(int j=0; j<n; j++) for(int k=0; k<adj[j].size(); k++) {
      v=adj[j][k], c=val[j][k];
      if(dist[v] > dist[j]+c) ok=1;
    }

    printf("%spossible\n", ok?"":"not ");
  }
  return 0;
}

