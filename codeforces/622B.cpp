#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;

int h, m;
int d;

int main() {
  scanf("%d:%d%d", &h, &m, &d);
  int t = h*60+m;
  t+=d;
  t%=24*60;
  printf("%02d:%02d\n", t/60, t%60);
  return 0;
}
