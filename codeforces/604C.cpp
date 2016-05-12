#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int n;
int s[100005];
vector<int> v;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%1d", &s[i]);

  int c = 1;
  int a = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) a++;
    else v.push_back(a), c++, a=1;
  }
  if (a != 1) v.push_back(a);

  int b[2] = {-1, -1};
  for (int i = 0; i < v.size(); ++i) if (v[i] > 1) { b[0] = i; break; }
  for (int i = v.size()-1; i >= 0; --i) if (v[i] > 1) { b[1] = i; break; }

  if (b[0] < 0) printf("%d\n", c);
  else if (b[0] != b[1] || (b[0] == b[1] && v[b[0]] > 2)) printf("%d\n", c+2);
  else printf("%d\n", c+1);

  return 0;
}
