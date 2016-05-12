#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n;
vector<int> v;

int main() {
  scanf("%d", &n);

  int i = 0;
  while (i < n) {
    v.push_back(1);
    while (v.size() > 1) {
      if (v[v.size()-1] == v[v.size()-2]) {
        int x = v.back();
        v.pop_back();
        v.pop_back();
        v.push_back(x+1);
      } else break;
    }
    i++;
  }

  for (int i = 0; i < v.size(); ++i) printf("%d ", v[i]);
  printf("\n");

  return 0;
}
