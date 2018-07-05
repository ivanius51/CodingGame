#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

//using namespace std;

int getVerticalDirrection(std::string strDir)
{
  if (std::string::npos != strDir.find("U"))
  {
    return -1;
  }
  else if (std::string::npos != strDir.find("D"))
  {
    return 1;
  }
  return 0;
}
int getHorizontalDirrection(std::string strDir)
{
  if (std::string::npos != strDir.find("L"))
  {
    return -1;
  }
  else if (std::string::npos != strDir.find("R"))
  {
    return 1;
  }
  return 0;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  int W; // width of the building.
  int H; // height of the building.
  int MaxW; // width of the building.
  int MaxH; // height of the building.
  std::cin >> MaxW >> MaxH; std::cin.ignore();
  int N; // maximum number of turns before game over.
  std::cin >> N; std::cin.ignore();
  int X0;
  int Y0;
  
  std::cin >> X0 >> Y0; std::cin.ignore();

  int X = X0;
  int Y = Y0;
  X0 = 0;
  Y0 = 0;
  W = MaxW - 1;
  H = MaxH - 1;
  std::cerr << W << "," << H << std::endl;

  int oldHDir = MaxW;
  int oldVDir = MaxH;
  // game loop
  while (1)
  {
    std::string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
    std::cin >> bombDir; std::cin.ignore();

    int HDir = getHorizontalDirrection(bombDir);
    int VDir = getVerticalDirrection(bombDir);

    std::cerr << bombDir << " " << HDir << "," << VDir << std::endl;
     
    if (HDir < 0)
      W = X - 1;
    else
      X0 = X + 1;

    if (VDir < 0)
      H = Y - 1;
    else
      Y0 = Y + 1;

    /*
    if (oldHDir == MaxW)
    {
      if (HDir > 0)
        W = MaxW - X;
      else
        W = X;
    }
    else if (HDir == 0)
    {
      W = 0;
    } 
    else if (HDir == oldHDir)
    {
      if (HDir < 0)
        W -= X0 - X;
      else
        W -= X - X0;
    }
    else //direction changed
    {
      if (HDir < 0)
        W -= 1 + X - X0;
      else
        W -= 1 + X0 - X;
      if (W == 0)
        W = VDir;
    }
    

    if (oldVDir == MaxH)
    {
      if (VDir > 0)
        H = MaxH - Y;
      else
        H = Y;
    }
    else if (VDir == 0)
    {
      H = 0;
    }
    else if (VDir == oldVDir)
    {
      if (VDir < 0)
        H -= Y0 - Y;
      else
        H -= Y - Y0;
    }
    else //direction changed
    {
      if (VDir < 0)
        H -= 1 + Y - Y0;
      else
        H -= 1 + Y0 - Y;
      if (H == 0)
        H = VDir;
    }

    //Y0 = Y;
    //X0 = X;

    //int X = X0 + ((W - X0) * HDir) / 2;
    */
    if (HDir != 0)
    {   
      X = X0 + (W - X0) / 2;
    }

    std::cout << X;
    std::cout << " ";

    if (VDir != 0)
    {
      Y = Y0 + (H - Y0) / 2;
    }

    std::cout << Y;
    std::cout << std::endl;

    std::cerr << W << "," << H << std::endl;

    //oldHDir = HDir;
    //oldVDir = VDir;
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    //U D R L

    // the location of the next window Batman should jump to.
    //cout << "0 0" << endl;
  }
}