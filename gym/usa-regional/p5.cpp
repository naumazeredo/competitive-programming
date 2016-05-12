#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int p, d, n;
int pn, s[3], e[3];

struct state {
  int a[3];
  bool operator<(const state s) const {
    if (a[0] < s.a[0]) return true;
    if (a[1] < s.a[1]) return true;
    return a[2] < s.a[2];
  }
};

struct mach {
  state s, e; char c;
};

vector<mach> machs;
map<state, mach> bt;

int main() {
  scanf("%d", &p);
  while (p--) {
    bt.clear();
    machs.clear();

    scanf("%d%d", &d, &n);
    for (int i = 0; i < 3; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);

      mach m;
      for (int j = 0; j < 3; ++j) m.s.a[j] = 0;
      m.s.a[i] = 1;
      m.e.a[0] = a; m.e.a[1] = b; m.e.a[2] = c;
      m.c = (i==0?'A':(i==1?'B':'C'));

      machs.push_back(m);

      mach m2;
      m2.s = m.e;
      m2.e = m.s;
      m2.c = m.c+'a'-'A';
      machs.push_back(m2);
    }

    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d%d%d%d%d", &pn, &s[0], &s[1], &s[2], &e[0], &e[1], &e[2]);

      queue<state> q;

      state start, end;
      for (int j = 0; j < 3; ++j) start.a[0] = s[0];
      for (int j = 0; j < 3; ++j) end.a[0] = 0;

      mach init; init.c = 0;
      bt[start] = init;

      q.push(start);
      while (!q.empty()) {
        state u = q.front(); q.pop();
        if (u.a[0] == e[0] && u.a[1] == e[1] && u.a[2] == e[2]) break;

        for (int i = 0; i < machs.size(); ++i) {
          mach m = machs[i];

          state dest;
          for (int j = 0; j < 3; ++j) dest.a[j] = u.a[j]-m.s.a[j]+m.e.a[j];

          if (u.a[0] <= m.s.a[0] && u.a[1] <= m.s.a[1] && u.a[2] <= m.s.a[2] && bt.find(dest) == bt.end()) {
            bt[dest] = m;
            q.push(dest);
          }
        }
      }
    }
  }
  return 0;
}
