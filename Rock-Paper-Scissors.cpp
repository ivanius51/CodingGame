#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char randMove(int random = 0)
{
  srand(random % 10 + rand());
  switch (rand() % 3)
  {
  case (0):
    return 'R';
    break;
  case(1):
    return 'P';
    break;
  case(2):
    return 'S';
    break;
  }
}

char counter(char move)
{
  if (move == 'R')
    return 'P';
  else if (move == 'P')
    return 'S';
  else
    return 'R';
}

int isWin(char tryWin, char opponent)
{
  if (tryWin != opponent)
  {
    if (counter(opponent) == tryWin)
      return 1;
    else
      return -1;
  }
  return 0;
}

int main()
{
  char lastmove;
  char myMove = randMove();
  bool tryCounter = false;
  int sucessCounter = 0;
  int oldSucessCounter = 0;
  int i = 0;
  // game loop
  while (1)
  {
    char opponentLastMove;
    cin >> opponentLastMove; cin.ignore();

    if (tryCounter)
    {
      oldSucessCounter = sucessCounter;
      sucessCounter += isWin(myMove, opponentLastMove);
    }
    myMove = randMove(i);
    if (i >= 1)
    {  
      if (i > 1 && lastmove == opponentLastMove)
      {
        if (sucessCounter>=-5)
        {
          myMove = counter(lastmove);   
          tryCounter = true;
        }
        else
        {
          if (oldSucessCounter > sucessCounter && (i % 2 == 0))
            myMove = counter(counter(lastmove));
          else
            myMove = lastmove;
          tryCounter = true;
        }
      }
      else
      {
        tryCounter = false;
        //myMove = counter(opponentLastMove);
      }
      lastmove = opponentLastMove;
    }
    cerr << tryCounter << " " <<  sucessCounter << endl;
    cout << myMove << endl;
    i++;
  }
}