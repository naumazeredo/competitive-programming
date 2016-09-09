#include <bits/stdc++.h>
using namespace std;

#define cl(x,v) memset((x),(v),sizeof(x))

const int N = 1e3+5;

// Suffix Array O(nlogn)
char s[N];
int n, r, ra[N], sa[N], tra[N], tsa[N], c[N]; // n = strlen(s)

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

// Longest Common Prefix with SA O(n)
int phi[N], plcp[N], lcp[N];
void calcLCP() {
  int l = 0;
  phi[sa[0]] = -1; plcp[sa[0]] = 0;
  for (int i = 1; i < n; ++i) phi[sa[i]] = sa[i-1];
  for (int i = 0; i < n; ++i) {
    if (phi[i] == -1) continue;
    while (s[i+l] == s[phi[i]+l]) l++;
    plcp[i] = l;
    l = max(l-1, 0);
  }
  for (int i = 0; i < n; ++i) lcp[i] = plcp[sa[i]];
}

// ---------------

char p[N];
int m;

int main() {
  int f = 0;
  while (~scanf("%s%s", s, p)) {
    m = strlen(s);
    strcat(s, "$"); strcat(s, p); strcat(s, "#");
    n = strlen(s);

    suffixarray();
    calcLCP();

    // Longest Common Substring O(n)
    // n = len first string; m = len second string
    int lcs = 0;
    for (int i = 1; i < n; ++i) if ((sa[i] < m) != (sa[i-1] < m))
      lcs = max(lcs, lcp[i]);

    if (!f) f = 1;
    else printf("\n");

    if (lcs) {
      vector<string> v;
      for (int i = 1; i < n; ++i) if ((sa[i] < m) != (sa[i-1] < m) and lcp[i] == lcs)
        v.push_back(string(s, sa[i], lcs));
      sort(v.begin(), v.end());
      v.resize(unique(v.begin(), v.end())-v.begin());
      for (string a : v) printf("%s\n", a.c_str());
    } else printf("No common sequence.\n");
  }
}
