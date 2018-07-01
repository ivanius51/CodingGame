#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  int N; // Number of elements which make up the association table.
  cin >> N; cin.ignore();
  unordered_map<string,string> MIMEtypes(N);
  int Q; // Number Q of file names to be analyzed.
  cin >> Q; cin.ignore();
  for (int i = 0; i < N; i++) 
  {
    string EXT; // file extension
    string MT; // MIME type.
    cin >> EXT >> MT; cin.ignore();
    std::transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
    MIMEtypes[EXT] = MT;
  }
  for (int i = 0; i < Q; i++) 
  {
    string FNAME; // One file name per line.
    getline(cin, FNAME);
    //cerr << FNAME << endl;
    size_t dotPos = FNAME.find_last_of('.');
    
    if (dotPos != string::npos)
    {
      string FEXT = FNAME.substr(dotPos + 1, FNAME.length() - dotPos);
      std::transform(FEXT.begin(), FEXT.end(), FEXT.begin(), ::tolower);
      auto currentMime = MIMEtypes.find(FEXT);
      if (currentMime == MIMEtypes.end())
      {
        cout << "UNKNOWN" << endl;
      }
      else
      {
        cout << currentMime->second << endl;
      }
    }
    else
    {
      cout << "UNKNOWN" << endl;
    }
  }

  // Write an action using cout. DON'T FORGET THE "<< endl"
  // To debug: cerr << "Debug messages..." << endl;


  // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
  //cout << "UNKNOWN" << endl;
}