#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
  int n, j;
  while (cin >> n >> j && n)
  {
    queue<int> deck;
    vector<int> discard;
    vector< vector<int> > pstack;
    pstack.resize(j);

    for (int i = 0; i < n; ++i)
    {
      int card;
      cin >> card;
      deck.push(card);
    }

    int p = 0;
    while (!deck.empty())
    {
      int card = deck.front();
      deck.pop();

      bool pass = false;

      vector<int>::iterator it;
      it = find(discard.begin(), discard.end(), card);
      if (it != discard.end())
      {
        // Discard pile
        discard.erase(it);
        pstack[p].push_back(card);
        pstack[p].push_back(card);
      }
      else
      {
        // Not on discard
        bool acted = false;
        for (int i = 1; i < j && !acted; ++i)
        {
          // In player's hand?
          int op = (p + i) % j;
          if (!pstack[op].empty() && pstack[op].back() == card)
          {
            for (unsigned int j = 0; j < pstack[op].size(); ++j)
              pstack[p].push_back(pstack[op][j]);
            pstack[op].clear();
            pstack[p].push_back(card);
            acted = true;
          }
        }

        if (!acted)
        {
          if (!pstack[p].empty() && pstack[p].back() == card)
          {
            pstack[p].push_back(card);
          }
          else
          {
            discard.push_back(card);
            pass = true;
          }
        }
      }

      if (pass)
        p = (p + 1) % j;
    }

    int biggest = 0;
    vector<int> winners;
    for (int i = 0; i < j; ++i)
    {
      int s = pstack[i].size();
      if (s > biggest)
      {
        biggest = s;
        winners.clear();
        winners.push_back(i+1);
      }
      else if (s == biggest)
      {
        winners.push_back(i+1);
      }
    }

    sort(winners.begin(), winners.end());
    cout << biggest;
    for (unsigned int i = 0; i < winners.size(); ++i)
      cout << " " << winners[i];
    cout << endl;
  }
}
