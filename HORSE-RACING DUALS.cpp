#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  int N;
  cin >> N; cin.ignore();
  vector<int> horsePi;
  for (int i = 0; i < N; i++)
  {
    int Pi;
    cin >> Pi; cin.ignore();
    //cerr << Pi << " ";
    horsePi.push_back(Pi);
  }
  //cerr << endl;
  std::sort(horsePi.begin(), horsePi.end());

  int closest = -1;
  for (auto it = horsePi.begin(); it != horsePi.end() - 1; ++it)
  {
    //cerr << *it << " ";
    int distance = abs(*it - *(it + 1));
    if (closest == -1 || closest > distance)
    {
      closest = distance;
    }
  }
  //cerr << endl;
  // Write an action using cout. DON'T FORGET THE "<< endl"
  // To debug: cerr << "Debug messages..." << endl;

  cout << closest << endl;
}