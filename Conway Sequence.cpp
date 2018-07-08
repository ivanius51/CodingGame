#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int getCountOfValue(std::vector<int> & data, int value, int * offset = 0)
{
  int result = 1;
  ++*offset;
  for (int i = *offset; i < data.size(); ++i)
  {
    if (data[i] == value)
    {
      result++;
      ++*offset;
    }
    else
      return result;
  }
  return result;
}

std::vector<int> Encode(std::vector<int> & toEncode)
{
  std::vector<int> encoded;
  int offset = 0;
  while (offset < toEncode.size())
  {
    int value = toEncode[offset];
    int countOfValues = getCountOfValue(toEncode, value, &offset);
    encoded.push_back(countOfValues);
    encoded.push_back(value);
    //cerr << countOfValues << " " << value << endl;
  }
  return encoded;
}

int main()
{
  int R;
  std::cin >> R; std::cin.ignore();
  int L;
  std::cin >> L; std::cin.ignore();

  std::vector<int> data(1);
  data[0] = R;

  for (int i = 1; i < L; ++i)
  {
    data = Encode(data);
  }
  for (auto it = data.begin(); it != data.end(); ++it)
  {
    std::cout << *it;
    if (it < data.end()-1)
      std::cout << ' ';
  }
  std::cout << std::endl;
}