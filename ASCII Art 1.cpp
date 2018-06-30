#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  int L;
  cin >> L; cin.ignore();
  int H;
  cin >> H; cin.ignore();
  string Text;
  getline(cin, Text);

  std::vector<std::string> alphabet(27, "");
  for (int i = 0; i < H; i++)
  {
    string ROW;
    getline(cin, ROW);
    for (int j = 'A'; j <= 'Z' + 1; ++j)
    {
      alphabet[j - 'A'] += ROW.substr((j - 'A')*L, L);
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (char& symbol : Text)
    {
      int pos = toupper(symbol) - 'A';
      if (pos < 0 || pos > 25)
      {
        cerr << pos << endl;
        pos = 26;
      }
      cout << alphabet[pos].substr(i*L, L);
    }
    cout << endl;
  }

  // Write an action using cout. DON'T FORGET THE "<< endl"
  // To debug: cerr << "Debug messages..." << endl;

  cout << "" << endl;
}