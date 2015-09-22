#include <bits/stdc++.h>
using namespace std;

int n, d;
pair<int, long long> sm[222222];
//int m[222222], s[222222];

int main() {
  cin >> n >> d;
  for (int i = 0; i < n; ++i) {
    int m, s;
    cin >> m >> s;
    sm[i] = make_pair(m, s);
  }

  sort(sm, sm+n);

  long long f = sm[0].second;
  long long m = f;
  int l = 0;
  for (int i = 1; i < n; ++i) {
    while (sm[i].first >= sm[l].first + d) {
      f -= sm[l++].second;
    }

    f += sm[i].second;
    m = max(f, m);
  }

  cout << m << endl;

  return 0;
}
