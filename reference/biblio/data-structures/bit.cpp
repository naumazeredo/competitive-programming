// Fenwick Tree / Binary Indexed Tree
int bit[N];

void add(int p, int v) {
  p+=2; for (; p<N; p+=p&-p) bit[p] += v;
}

int query(int p) {
  p+=2; int r = 0;
  for (; p; p-=p&-p) r += bit[p];
  return r;
}
