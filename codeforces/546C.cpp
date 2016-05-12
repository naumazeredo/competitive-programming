#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int n, k1, k2, t;
//int c1[20], c1[20];
queue<int> c1, c2;

vector< pair< queue<int>, queue<int> > > history;

int main() {
  scanf("%d", &n);
  scanf("%d", &k1);
  for (int i = 0; i < k1; ++i) {
    scanf("%d", &t);
    c1.push(t);
  }

  scanf("%d", &k2);
  for (int i = 0; i < k2; ++i) {
    scanf("%d", &t);
    c2.push(t);
  }

  int cnt = 0;
  while (!c1.empty() && !c2.empty() &&
         find(history.begin(), history.end(), make_pair(c1, c2)) == history.end()) {
    history.push_back(make_pair(c1, c2));

    cnt++;
    int a = c1.front(), b = c2.front();
    c1.pop(); c2.pop();
    if (a > b) {
      c1.push(b); c1.push(a);
    } else {
      c2.push(a); c2.push(b);
    }
  }

  if (c1.empty()) printf("%d 2\n", cnt);
  else if (c2.empty()) printf("%d 1\n", cnt);
  else printf("-1\n");
}
