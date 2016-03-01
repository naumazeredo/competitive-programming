#include <cstdio>
#include <cstring>
#include <cstdlib>

int x[9], // Queen x's
    TC,   // Total cases
    a, b, // Queen position
    lineCounter;

bool place(int queen, int row)
{
  for (int prev = 1; prev <= queen - 1; ++prev)
    if (x[prev] == row || (abs(x[prev] - row) == abs(prev - queen)))
      return false;
  return true;
}

void nqueens(int queen)
{
  for (int row = 1; row <= 8; ++row)
  {
    if (place(queen, row)) // if we can place this queen at this row
    {
      x[queen] = row; // put this queen in this row
      if (queen == 8 && x[b] == a)
      {
        printf("%2d      %d", ++lineCounter, x[1]);
        for (int i = 2; i <= 8; ++i)
          printf(" %d", x[i]);
        printf("\n");
      }
      else
        nqueens(queen + 1);
    }
  }
}

int main()
{
  scanf("%d", &TC);
  while (TC--)
  {
    scanf("%d %d", &a, &b);
    memset(x, 0, sizeof(x));
    lineCounter = 0;

    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    nqueens(1);
    if (TC) printf("\n");
  }

  return 0;
}
