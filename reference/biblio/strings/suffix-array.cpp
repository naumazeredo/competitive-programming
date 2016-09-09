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
