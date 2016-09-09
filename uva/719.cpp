#include <bits/stdc++.h>
using namespace std;

#define cl(x,v) memset((x),(v),sizeof(x))

const int N = 1e5+5;
char s[N];
int n, r, ra[N], sa[N], tra[N], tsa[N], c[N];

void count(int k) {
  int sum = 0, x = max(300, n); cl(c, 0);
  for (int i = 0; i < n; ++i) c[i+k<n ? ra[i+k] : 0]++;
  for (int i = 0; i < x; ++i) sum += c[i], c[i] = sum-c[i];
  for (int i = 0; i < n; ++i) tsa[c[sa[i]+k<n ? ra[sa[i]+k] : 0]++] = sa[i];
  for (int i = 0; i < n; ++i) sa[i] = tsa[i];
}

void suffixarray() {
  for (int i = 0; i < n; ++i) ra[i] = s[i], sa[i] = i;
  for (int k = 1; k < n; k <<= 1) {
    count(k); count(0);
    tra[sa[0]] = r = 0;
    for (int i = 1; i < n; ++i)
      tra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] and ra[sa[i]+k] == ra[sa[i-1]+k]) ? r : ++r;
    for (int i = 0; i < n; ++i) ra[i] = tra[i];
    if (ra[sa[n-1]] == n-1) break;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int m = strlen(s);
    strcat(s, s);
    n = strlen(s);
    s[n++] = '$';
    suffixarray();

    //for (int i = 0; i < n; ++i) printf("%2d: %s\n", i, s+sa[i]);

    for (int i = 0; i < n; ++i) if (n - sa[i] > m) {
      if (i < n-1 and strncmp(s+sa[i], s+sa[i+1], m) == 0) continue;
      int ans = sa[i]+1;
      printf("%d\n", ans + (ans>m?-m:0));
      break;
    }
  }
}
