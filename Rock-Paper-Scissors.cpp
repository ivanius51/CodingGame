#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char randMove(int seed = 0)
{
  srand(seed % 10 + rand());
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
  char opponentPrevMove;
  char myLastMove = 0;
  char myMove = randMove();
  bool tryCounter = false;
  int sucessCounter = 0;
  int oldSucessCounter = 0;
  int streak = 0;
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
    if (isWin(myMove, opponentLastMove))
    {
      streak++;
    }
    else
    {
      streak = 0;
    }

    myMove = 0;
    if (i >= 1)
    {
      if (i > 1 && opponentPrevMove == opponentLastMove)
      {
        if (sucessCounter >= -3)
        {
          myMove = counter(opponentPrevMove);
          tryCounter = true;
        }
        else
        {
          if (oldSucessCounter > sucessCounter && (i % 2 == 0))
            myMove = counter(randMove(i));
          else
            myMove = counter(myLastMove);
          tryCounter = true;
        }
      }
      else
      {
        tryCounter = false;
        myMove = (myLastMove);
      }
      opponentPrevMove = opponentLastMove;
    }  
    if (myMove == 0)
    {
      myMove = randMove(i);
    }
    else
    {
      myLastMove = myMove;
    }
    cerr << "streak=" << streak << " tryCounter=" << tryCounter << " sucessCounter=" << sucessCounter << endl;
    cout << myMove << endl;
    i++;
  }
}