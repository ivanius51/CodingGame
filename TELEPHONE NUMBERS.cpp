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
  int N;
  cin >> N; cin.ignore();

  std::unordered_map<std::string, int> duplicated;
  std::vector<std::string> numbers(N, "");
  int count = 0;

  for (int i = 0; i < N; i++)
  {
    string telephone;
    cin >> telephone; cin.ignore();
    numbers[i] = telephone;
    //cerr << telephone << endl;
    count += telephone.length();
  }
  for (int i = 0; i < N; i++)
  {
    std::string currentNumber = numbers[i];
    for (int j = i + 1; j < N; j++)
    {
      for (int testCount = numbers[j].length(); testCount > 0; --testCount)
      {
        std::string testStr = currentNumber.substr(0, testCount);
        if (testStr == numbers[j].substr(0, testCount))
        {
          if (duplicated.find(testStr) == duplicated.end())
          {
            //cerr << testStr << "=" << numbers[j].substr(0, testCount) << endl;
            duplicated[testStr] = 0;
          }
          break;
        }
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    std::string currentNumber = numbers[i];
    for (int testCount = currentNumber.length(); testCount > 0; --testCount)
    {
      std::string testStr = currentNumber.substr(0, testCount);
      if (duplicated.find(testStr) != duplicated.end())
      {
        //cerr << testStr << "=" << testStr.length() << endl;
        duplicated[testStr]++;
        break;
      }
    }
  }

  cerr << duplicated.size() << endl;
  for (auto it = duplicated.begin(); it != duplicated.end(); ++it)
  {
    if (it->second >= 2)
      count -= (it->second - 1)*it->first.length();
    else
      count -= it->first.length();
  }
  

  cout << count << endl;
}