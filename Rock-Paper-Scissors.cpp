#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <math.h>

using namespace std;

namespace constants
{
  const int basic = 1;
  const int randomCounterCalculation = 2;
  const int counterDouble = 4;
}

bool hasBehavior(size_t container, size_t behavior)
{
  return container & behavior ~= 0;
}

char randMove(int seed = 0)
{
  srand(time(NULL) + seed);
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
  int enemyStreak = 0;
  int enemyScore = 0;
  size_t i = rand() + 11;

  size_t strategy = constants::basic | constants::counterDouble;

  // game loop
  while (1)
  {
    char opponentLastMove;
    cin >> opponentLastMove; cin.ignore();
    myLastMove = myMove;

    myMove = 0;
    if (i >= 1)
    {
      if (tryCounter)
      {
        oldSucessCounter = sucessCounter;
        sucessCounter += isWin(myLastMove, opponentLastMove);
      }

      //calc scores
      int lastTurnResult = isWin(myLastMove, opponentLastMove);
      if (lastTurnResult == 1)
      {
        streak++;
        enemyStreak = 0;
      }
      else if (lastTurnResult == -1)
      {
        enemyStreak++;
        streak = 0;
        enemyScore += min(enemyStreak, 5);
      }
      else
      {
        streak = 0;
        enemyStreak = 0;
      }

      tryCounter = false;

      //stategies change condition
      if (enemyStreak > 3)
      {
        strategy = strategy | constants::randomCounterCalculation;
      }
      else if (sucessCounter < -3)
      {
        strategy = strategy & !constants::counterDouble;
      }
      else if (sucessCounter >= -3)
      {

      }

      //stategies
      if ((enemyStreak >= 1) && hasBehavior(strategy, constants::randomCounterCalculation))
      {
        myMove = randMove(i);
        cerr << "random ";
      }
      else if ((i > 1) && opponentPrevMove == opponentLastMove)
      {
        enemyScore += 2;

        if (sucessCounter >= -3)
        {
          myMove = counter(opponentPrevMove);
          tryCounter = true;
        }
        else
        {
          if (oldSucessCounter > sucessCounter && (i % 2 == 0))
          {
            myMove = counter(randMove(i));
          }
          else
          {
            myMove = counter(myLastMove);
            tryCounter = true;
          }
        }
      }
      else
      {
        if (streak < 2)
        {
          //myMove = myLastMove;
        }
        else
        {
          //myMove = counter(counter(myLastMove));
        }
      }
      opponentPrevMove = opponentLastMove;
    }
    if (myMove == 0)
    {
      myMove = randMove(i);
    }
    cerr << "enemyStreak=" << enemyStreak << " enemyScore=" << enemyScore << " tryCounter=" << tryCounter << " sucessCounter=" << sucessCounter << endl;
    cout << myMove << endl;
    i++;
  }
}