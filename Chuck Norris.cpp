#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  string MESSAGE;
  getline(cin, MESSAGE);

  string binary = "";

  for (int i = 0; i < MESSAGE.length(); ++i)
  {
    std::bitset<7> birdata = int(MESSAGE[i]);
    binary += birdata.to_string();
  }

  cerr << binary << endl;

  for (int i = 0; i < binary.length(); ++i)
  {
    if (binary[i] == '0')
    {
      cout << "00 ";
    }
    else
    {
      cout << "0 ";
    }
    char current = binary[i];
    while (current == binary[i] && i++ < binary.length())
    {
      cout << "0";
    }
    if (i < binary.length())
    {
      cout << " ";
      --i;
    }
  }

  // Write an action using cout. DON'T FORGET THE "<< endl"
  // To debug: cerr << "Debug messages..." << endl;

  cout << endl;
}