#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

typedef pair<int, int> ii;

int r[N];
int p[N];
int c[N];
int n[N];
int k, w;

int find(int x) {
    return p[x] == x ? x : x = find(p[x]);
}

int uni(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return c[px];
    if (r[px] < r[py]) p[px]=py, c[py] += c[px];
    else {
        p[py] = px, c[px] += c[py];
        if (r[px] == r[py]) r[px]++;
    }
    return 0;
}

int main() {
    while (scanf("%d%d", &k, &w) != EOF && k) {
        map<int, int> m;
        set<ii> sp;

        for (int i = 0; i < N; ++i)
            p[i] = i, r[i]=1, c[i]=1, n[i]=0;

        int ok = 1, cnt = 0;
        for (int i = 0; i < w; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            if (!ok) continue;

            if (m.find(a) == m.end()) m[a] = cnt++;
            if (m.find(b) == m.end()) m[b] = cnt++;
            int x = min(m[a], m[b]);
            int y = max(m[a], m[b]);
            a = x, b = y;

            if (sp.find(ii(a, b)) != sp.end()) continue;
            else sp.insert(ii(a, b));

            if (n[a] == 2 || n[b] == 2) ok=0; 
            if (uni(a, b) && c[find(a)] != k) ok=0;

            n[a]++; n[b]++;
        }

        if (ok) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
