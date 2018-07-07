#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int width; // the number of cells on the X axis
int height; // the number of cells on the Y axis
std::vector<std::string> lines;

void printRight(int px, int py)
{
  for (int x = px + 1; x < width; ++x)
  {
    if (lines[py][x] == '0')
    {
      cout << x << " " << py;
      return;
    }
  }
  cout << "-1 -1";
  /*
  for (int x = px - 1; x > 0; --x)
  {
    if (lines[py][x] == '0')
    {
      cout << x - px << " " << py;
      break;
    }
  }
  */
}
void printBottom(int px, int py)
{
  for (int y = py + 1; y < height; ++y)
  {
    if (lines[y][px] == '0')
    {
      cout << px << " " << y;
      return;
    }
  }
  cout << "-1 -1";
  /*
  for (int y = py - 1; y > 0; --y)
  {
    if (lines[y][px] == '0')
    {
      cout << px << " " << y - py;
      break;
    }
  }
  */
}

int main()
{
  cin >> width; cin.ignore();
  cin >> height; cin.ignore();
  lines.resize(height);
  for (int y = 0; y < height; y++)
  {
    //string line; // width characters, each either 0 or .
    getline(cin, lines[y]);
    cerr << lines[y] << endl;
    /*
    for (int x = 0; x < width; ++x)
    {
      if (lines[y][x] == '0')
      {
        //cerr << "x=" << x << " y=" << y << endl;
      }
    }
    */
  }
  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < width; ++x)
    {
      if (lines[y][x] == '0')
      {
        cerr << "x=" << x << " y=" << y << endl;
        cout << x << " " << y;
        cout << " ";
        printRight(x, y);
        cout << " ";
        printBottom(x, y);
        cout << endl;
      }
    }
  }

  //cout << "0 0 1 0 0 1" << endl;
  //cout << "1 0 -1 -1 -1 -1" << endl;
}