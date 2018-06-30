#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

//using namespace std;

int endSpeedStepSpeed(int height, float gravity, int maxAcceleration,  float speed = 0)
{
  int curHeight = height;
  float curSpeed = speed;
  int acceleration = 0;
  while (curHeight > 0)
  {
    curSpeed += (gravity + acceleration);
    if (curSpeed < 0)
    {
      curHeight += curSpeed;
    }
    else
    {
      curHeight -= curSpeed;
    }
    if (acceleration < maxAcceleration)
    {
      acceleration++;
    }
  }
  return std::floor(curSpeed);
}
int endSpeed(int height, float gravity, int acceleration, float speed = 0)
{
  int curHeight = height;
  float curSpeed = speed;
  while (curHeight > 0)
  {
    curSpeed += (gravity + acceleration);
    if (curSpeed < 0)
    {
      curHeight += curSpeed;
    }
    else
    {
      curHeight -= curSpeed;
    }
  }
  return std::floor(curSpeed);
}

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{

  std::vector<int> landPoints;
  int surfaceN; // the number of points used to draw the surface of Mars.
  std::cin >> surfaceN; std::cin.ignore();
  for (int i = 0; i < surfaceN; i++)
  {
    int landX; // X coordinate of a surface point. (0 to 6999)
    int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
    std::cin >> landX >> landY; std::cin.ignore();
    landPoints.push_back(landX);
    landPoints.push_back(landY);
  }

  int signalDelay = 100;
  float g = -3.711f;

  int landHeight = -1;
  int oldvSpeed = 0;

  int angleToRotate = 0;
  int speedToLanding = 0;

  // game loop
  while (1)
  {
    int X;
    int Y;
    int hSpeed; // the horizontal speed (in m/s), can be negative.
    int vSpeed; // the vertical speed (in m/s), can be negative.
    int fuel; // the quantity of remaining fuel in liters.
    int rotate; // the rotation angle in degrees (-90 to 90).
    int power; // the thrust power (0 to 4).
    std::cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; std::cin.ignore();

    if (landHeight == -1)
    {
      for (int i = 0; i < surfaceN; i++)
      {
        if (X < landPoints.at(i * 2))
        {
          landHeight = landPoints.at(i * 2 - 1);
          std::cerr << landHeight << std::endl;
          break;
        }
      }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    if (rotate == 0)//and position X is on flat land
    {
      angleToRotate = 0;
    }

    int verticalDistance = Y - landHeight;

    std::cerr << endSpeed(verticalDistance, g, speedToLanding, vSpeed) << std::endl;
    std::cerr << endSpeedStepSpeed(verticalDistance, g, 4, vSpeed) << std::endl;

    if ((endSpeedStepSpeed(verticalDistance, g, 4, vSpeed) <= -40) && (endSpeed(verticalDistance, g, speedToLanding, vSpeed) <= -40))
    {
      if (speedToLanding < 4)
      {
        speedToLanding++;
      }
    }
    else
    {
      if (speedToLanding > 0 && (endSpeed(verticalDistance, g, 4, vSpeed) >= -40))
      {
        speedToLanding--;
      }
    }
    // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).

    std::cout << angleToRotate;
    std::cout << " ";
    std::cout << speedToLanding;
    std::cout << std::endl;
  }
}