#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
  int n;
  cin >> n; cin.ignore();
  int values[n];
  int vmax;
  int nextVMax;
  int vmin;
  int p = 0;

  for (int i = 0; i < n; i++)
  {
    int v;
    cin >> v; cin.ignore();
    //cerr << v << endl;
    values[i] = (v);
  }

  for (int i = 0; i < n; i++)
  {
    int v = values[i];
    for (int j = i + 1; j < n; j++)
    {
      if (v > values[j])
      {
        //cerr << v << ">" << values[j] << endl;
        vmin = values[j];
        vmax = v;
        if (p > (vmin - vmax))
        {
          p = vmin - vmax;
        }
      }
      else
      {
        //cerr << v << "<=" << values[j] << endl;
        i = j - 1;
        break;
      }
    }
  }

  cout << p << endl;
}