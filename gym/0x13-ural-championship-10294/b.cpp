#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int N = 3e6;

int d[N];
int p[N];
int n;

int main() {
  //for (ll i = 1; i*i < N; ++i) for (ll j = 1; i*j < N; ++j) d[i*j]++;
  for (ll i = 1; i < N; ++i) for (ll j = i; j < N; j+=i) d[j]++;

  scanf("%d", &n);

  int ind = 0;
  p[1] = 1;
  p[2] = 1;
  for (int i = 3; i < N; ++i) {
    p[i] = i>d[i] ? 1+p[i-d[i]] : 0;
    if (p[i] == n) {ind = i; break;}
  }

  vector<int> v;
  for (int i = 0; i < n; ++i) {
    v.push_back(d[ind]);
    ind -= d[ind];
  }

  for (int i = 0; i < n; ++i) {
    printf("%d ", v.back());
    v.pop_back();
  }
  printf("\n");

  return 0;
}
