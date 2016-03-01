#include <bits/stdc++.h>
using namespace std;

int t;

string s;

int main() {
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    printf("Case %d\n", tt);

    map<char, int> m;
    stack<char> l;
    cin >> s;
    for (int i = 0; i < (int)s.length(); ++i) {
      if (m.find(s[i]) == m.end()) m[s[i]] = 1;
      if (l.empty()) {
        m[s[i]] = 0;
        l.push(s[i]);
      } else if (s[i] == l.top()) {
        l.pop();
      } else {
        if (!l.empty()) m[l.top()]++;
        l.push(s[i]);
      }
    }

    for (auto i = m.begin(); i != m.end(); ++i) {
      printf("%c = %d\n", i->first, i->second);
    }
  }

  return 0;
}
