#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void penaltyDrops(int N, string sofar)
{
  if (N % 3 != 0)
  {
    return;
  }
  cout << sofar << N / 3 << endl;
}
void transformations(int N, int sofar)
{
  int tries = min(sofar, N / 2);
  for (int i = 0; i <= tries; i++)
  {
    char buff[255];
    snprintf(buff, sizeof(buff), "%d %d ", sofar, i);
    std::string sofarstr = buff;
    penaltyDrops(N - i * 2, sofarstr);
  }
}
void tries(int N)
{
  int tries = N / 5;
  for (int i = 0; i <= tries; i++)
  {
    transformations(N - i * 5, i);
  }
}    

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  int N;
  cin >> N; cin.ignore();

  cerr << N << endl;
  // Write an action using cout. DON'T FORGET THE "<< endl"
  // To debug: cerr << "Debug messages..." << endl;

  tries(N);
}

