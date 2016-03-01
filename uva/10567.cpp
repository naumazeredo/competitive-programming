#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

char s[1000005], t[128];
int x;

vector<int> p[300];

int main() {
  scanf("%s%d", s, &x);
  int len = strlen(s);
  for (int i = 0; i < len; ++i) p[s[i]].pb(i);

  for (int i = 0; i < x; ++i) {
    scanf(" %s", t);

    int f = INF, l = -1, ok = 1;
    for (int j = 0; j < strlen(t) and ok; ++j) {
      int pos = lower_bound(p[t[j]].begin(), p[t[j]].end(), l+1)-p[t[j]].begin();
      if (pos < p[t[j]].size()) f = min(f, p[t[j]][pos]), l = p[t[j]][pos];
      else ok = 0;
    }

    if (ok) printf("Matched %d %d\n", f, l);
    else printf("Not matched\n");
  }
  return 0;
}
