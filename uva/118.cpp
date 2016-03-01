#include <bits/stdc++.h>
using namespace std;

int w, h;
int x, y;
char o;

int l;
set<pair<int, int> > lost;

int main() {
  scanf("%d %d", &w, &h);
  while (scanf("%d %d %c ", &x, &y, &o) != EOF) {
    string str;
    cin >> str;
    l = 0;
    for (int i = 0; i < (int)str.length(); ++i) {
      if (str[i] == 'F') {
        if (o == 'N') {
          if (y+1>h) {
            if (lost.find(make_pair(x,y)) == lost.end()) {
              lost.insert(make_pair(x,y));
              printf("%d %d %c LOST\n", x, y, o);
              l = 1;
              break;
            }
            y--;
          }
          y++;
        } else if (o == 'S') {
          if (y-1<0) {
            if (lost.find(make_pair(x,y)) == lost.end()) {
              lost.insert(make_pair(x,y));
              printf("%d %d %c LOST\n", x, y, o);
              l = 1;
              break;
            }
            y++;
          }
          y--;
        } else if (o == 'E') {
          if (x+1>w) {
            if (lost.find(make_pair(x,y)) == lost.end()) {
              lost.insert(make_pair(x,y));
              printf("%d %d %c LOST\n", x, y, o);
              l = 1;
              break;
            }
            x--;
          }
          x++;
        } else if (o == 'W') {
          if (x-1<0) {
            if (lost.find(make_pair(x,y)) == lost.end()) {
              lost.insert(make_pair(x,y));
              printf("%d %d %c LOST\n", x, y, o);
              l = 1;
              break;
            }
            x++;
          }
          x--;
        }
      } else if (str[i] == 'L') {
        if (o == 'N') o = 'W';
        else if (o == 'W') o = 'S';
        else if (o == 'S') o = 'E';
        else if (o == 'E') o = 'N';
      } else if (str[i] == 'R') {
        if (o == 'N') o = 'E';
        else if (o == 'W') o = 'N';
        else if (o == 'S') o = 'W';
        else if (o == 'E') o = 'S';
      }
    }

    if (!l) printf("%d %d %c\n", x, y, o);
  }

  return 0;
}
