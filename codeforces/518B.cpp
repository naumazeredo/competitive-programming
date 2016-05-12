#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int s[300000];
int cnt[500];
int t[300000];
int a, b;

char changeCase(char c) {
  int delta = 'A' - 'a';
  if (c >= 'a' && c <= 'z')
    return c + delta;
  return c - delta;
}

int main() {
  memset(t, 0, sizeof(t));
  memset(cnt, 0, sizeof(cnt));
  a = b = 0;

  char c;
  int l = 0;
  while (scanf("%c", &c) && c != '\n')
    s[l++] = c;
  while (scanf("%c", &c) && c != '\n')
    cnt[c]++;

  for (int i = 0; i < l; ++i) {
    if (cnt[s[i]] > 0) {
      a++;
      cnt[s[i]]--;
      t[i] = 1;
    }
  }

  for (int i = 0; i < l; ++i) {
    c = changeCase(s[i]);
    if (!t[i] && cnt[c] > 0) {
      b++;
      cnt[c]--;
    }
  }

  printf("%d %d\n", a, b);
  return 0;
}
