#include <iostream>
#include <map>
using namespace std;

int main()
{
  int n;
  cin >> n;

  map<int, int> votes;
  int winner;
  int winnerVotes = 0;
  for (int i = 0; i < n; ++i)
  {
    int v;
    cin >> v;

    if (votes.find(v) != votes.end())
      votes[v]++;
    else
      votes[v] = 1;

    int curVotes = votes[v];
    if (curVotes > winnerVotes)
    {
      winner = v;
      winnerVotes = curVotes;
    }
  }

  cout << winner << endl;
}
