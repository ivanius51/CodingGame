#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::string getDirection(int clonePos, int exitOrElevatorPos)
{
  if (clonePos - exitOrElevatorPos == 0)
    return "NONE";
  else if (clonePos - exitOrElevatorPos < 0)
    return "LEFT";
  else
    return "RIGHT";
}

int main()
{
  int nbFloors; // number of floors
  int width; // width of the area
  int nbRounds; // maximum number of rounds
  int exitFloor; // floor on which the exit is found
  int exitPos; // position of the exit on its floor
  int nbTotalClones; // number of generated clones
  int nbAdditionalElevators; // ignore (always zero)
  int nbElevators; // number of elevators
  cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();

  std::vector<int> elevators(nbElevators, 0);

  for (int i = 0; i < nbElevators; i++)
  {
    int elevatorFloor; // floor on which this elevator is found
    int elevatorPos; // position of the elevator on its floor
    cin >> elevatorFloor >> elevatorPos; cin.ignore();
    elevators[elevatorFloor] = elevatorPos;
  }

  // game loop
  while (1)
  {
    int cloneFloor; // floor of the leading clone
    int clonePos; // position of the leading clone on its floor
    string direction; // direction of the leading clone: LEFT or RIGHT
    cin >> cloneFloor >> clonePos >> direction; cin.ignore();

    cerr << direction << endl;

    if (direction == "NONE")
    {
      cout << "WAIT";
    }
    else  if (cloneFloor == exitFloor)
    {
      cerr << clonePos - exitPos << endl;
      if (direction == getDirection(clonePos, exitPos))
        cout << "BLOCK";
      else
        cout << "WAIT";
    }
    else
    {
      cerr << clonePos - elevators[cloneFloor] << endl;
      if (direction == getDirection(clonePos, elevators[cloneFloor]))
        cout << "BLOCK";
      else
        cout << "WAIT";
    }

    cout << endl; // action: WAIT or BLOCK
  }
}