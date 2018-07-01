#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

double PI_DIV_180 = 3.14159265358979323846 / 180.0;

long double distance1(long double lonA, long double latA, long double lonB, long double latB)
{
  long double x = (lonB - lonA) * cos((latA + latB) / 2);
  long double y = (latB - latA);
  return (std::sqrt(x * x + y * y) * 6371);
}

double distance(double lon, double lat, double dlon, double dlat) {

  double x = (lon - dlon)*cos((lat + dlat) / 2);
  double y = lat - dlat;
  return sqrt(x*x + y * y) * 6371;

}

size_t find_nth(const string& haystack, const string& needle, size_t nth)
{
  size_t found_pos = haystack.find(needle);
  for (int i = 0; i < nth; ++i)
  {
    if (string::npos == found_pos)
    {
      break;
    }
    found_pos = haystack.find(needle, found_pos + 1);
  }
  return found_pos;
}

struct defibrillator
{
public:
  defibrillator(string data);
  string Id, Name, Address, Phone;
  double Lon, Lat;
};

defibrillator::defibrillator(string data)
{
  stringstream streamData(data);
  string field;
  int i = 0;
  while (getline(streamData, field, ';'))
  {
    switch (i)
    {
    case (0):
      Id = field;
      break;
    case (1):
      Name = field;
      break;
    case (2):
      Address = field;
      break;
    case (3):
      Phone = field;
      break;
    case (4):
      Lon = std::stold(field.replace(field.find(","), 1, "."));
      break;
    case (5):
      Lat = std::stold(field.replace(field.find(","), 1, "."));
      break;
    }
    i++;
  }
}

int main()
{
  string LON;
  cin >> LON; cin.ignore();
  double myLon = std::stold(LON.replace(LON.find(","), 1, "."));
  string LAT;
  cin >> LAT; cin.ignore();
  double myLat = std::stold(LAT.replace(LAT.find(","), 1, "."));
  int N;
  cin >> N; cin.ignore();

  vector<defibrillator> DEFIBs;

  std::cerr.precision(16);

  for (int i = 0; i < N; i++) {
    string DEFIB;
    getline(cin, DEFIB);
    DEFIBs.push_back(defibrillator(DEFIB));
    /*
    int pos = find_nth(DEFIB, ";", 3);
    if (pos != string::npos)
    {
      //cerr << DEFIB << endl;
      size_t tempPos = pos + 1;
      size_t tempPosEnd = DEFIB.find(";", tempPos);
      size_t comaPos = DEFIB.find(",", tempPos) - tempPos;
      string toConvert = DEFIB.substr(tempPos, tempPosEnd - tempPos).replace(comaPos, 1, ".");
      long double lonO = std::stold(toConvert);
      comaPos = DEFIB.find(",", tempPosEnd) - tempPosEnd - 1;
      toConvert = DEFIB.substr(tempPosEnd + 1, DEFIB.length()).replace(comaPos, 1, ".");
      long double latO = std::stold(toConvert);
      //long double converted = std::stold(toConvert);
      //cerr << toConvert << "=" << converted << endl;
      long double dist = distance(lonO, latO, myLon, myLat);
      //cerr << dist << "=" << DEFIB << endl;
      if (i == 0 || bestDist > dist)
      {
        cerr << dist << "=" << DEFIB << endl;
        bestDist = dist;
        bestPoint = DEFIB;
      }
    }
    */
  }

  long double bestDist = -1;
  string bestPoint;

  for (auto defib = DEFIBs.begin(); defib != DEFIBs.end(); ++defib)
  {
    double dist = distance(defib->Lon, defib->Lat, myLon, myLat);
    if (bestDist == -1 || bestDist > dist)
    {
      bestDist = dist;
      bestPoint = defib->Name;
      cerr << bestDist << " " << bestPoint << endl;
    }
  }

  cout << bestPoint << endl;

  //cout << bestPoint.substr(nameStart, nameEnd - nameStart) << endl;

}