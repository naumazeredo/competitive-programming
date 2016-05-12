#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main() {
    char s;
    char c = 0;
    int ok = 1;
    while (1) {
        scanf("%c", &s);
        if (s == '*') break;
        if (s >= 'A' && s <= 'Z') s += 'a' - 'A';
        if (c == 0) c = s;

        if (s == '\n') {
            printf("%c\n", ok?'Y':'N');
            c = 0; ok = 1;
        } else if (s == ' ') {
            scanf(" %c", &s);
            if (s >= 'A' && s <= 'Z') s += 'a' - 'A';
            if (c != s) ok = 0;
        }
    }
    return 0;
}
