#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int W; // number of columns.
int H; // number of rows.
std::vector <std::vector<int>> mapLines;

void printWay(int XI, int YI, std::string POS)
{
  int X = XI;
  int Y = YI;
  switch (mapLines[YI][XI])
  {
  case(1):
    Y++;
    break;
  case(2):
    if (POS == "LEFT")
      X++;
    else
      X--;
    break;
  case(3):
    Y++;
    break;
  case(4):
    if (POS == "TOP")
      X--;
    else
      Y++;
    break;
  case(5):
    if (POS == "TOP")
      X++;
    else
      Y++;
    break;
  case(6):
    if (POS == "LEFT")
      X++;
    else
      X--;
    break;
  case(7):
    Y++;
    break;
  case(8):
    Y++;
    break;
  case(9):
    Y++;
    break;
  case(10):
    X--;
    break;
  case(11):
    X++;
    break;
  case(12):
    Y++;
    break;
  case(13):
    Y++;
    break;
  }
  cout << X << " " << Y << endl;
}

int main()
{
  cin >> W >> H; cin.ignore();
  mapLines.resize(H, std::vector<int>(W));
  cerr << W << " " << H << endl;
  for (int i = 0; i < H; i++)
  {
    std::string num;
    for (int j = 0; j < W; j++)
    {
      cin >> mapLines[i][j];
      cerr << mapLines[i][j];
    }
    cerr << endl;
  }
  int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
  cin >> EX; cin.ignore();

  // game loop
  while (1)
  {
    int XI;
    int YI;
    string POS;
    cin >> XI >> YI >> POS; cin.ignore();

    // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
    //cout << "0 0" << endl;
    printWay(XI, YI, POS);
  }
}