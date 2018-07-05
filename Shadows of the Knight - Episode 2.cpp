#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  int W; // width of the building.
  int H; // height of the building.
  std::cin >> W >> H; std::cin.ignore();
  int N; // maximum number of turns before game over.
  std::cin >> N; std::cin.ignore();
  int X0;
  int Y0;
  int X;
  int Y;
  std::cin >> X0 >> Y0; std::cin.ignore();



  // game loop
  while (1)
  {
    std::string bombDir; // Current distance to the bomb compared to previous distance (COLDER, WARMER, SAME or UNKNOWN)
    std::cin >> bombDir; std::cin.ignore();

    std::cerr << bombDir << std::endl;

    if (bombDir == "UNKNOWN")
    {
      X = W / 2;
      Y = H / 2;
    }
    else if (bombDir == "WARMER")
    {
      //(x - x1)/(x2 - x1) = (y - y1)/(y2 - y1) ->  (y2 - y1)X + (x2 - x1)Y + (x1 * y2 - x2 * y1) -> Ax + By + C = 0;
      //y = kx + b;
      //{y1 = kx1 + b
      //{y2 = kx2 + b
      //double k1 = (y2 - y1) / (x2 - x1);
      //double b1 = (x2 * y1 - x1 * y2) / (x2 - x1);
      //y = kx + b;
      //x = (y - b) / k;
      /*
      int dx = (X - X0);
      int dy = (Y - Y0);

      float midY = Y0 + dy;
      float midX = X0 + dx;

      int x1 = X0;
      int y1 = Y0;
      int x2 = X;
      int y2 = Y;

      double k1 = (y2 - y1) / (x2 - x1);
      double b1 = (x2 * y1 - x1 * y2) / (x2 - x1);

      double k2 = -1 / k1;
      double b2 = y2 + k2 * x2;

      
      for (int i = 0; i < W; ++i)
      {
        if (i != 0)
        {
          std::cerr << ", ";
        }
        std::cerr << "y" << i << "=" << std::ceil(k2 * i + b2);
      }
      std::cerr << std::endl;

      
      if (H > W)
      {
        Y = std::ceil(H - ((H - (k2 * X + b2)) / 2));
      }
      else
      {
        X = std::ceil((Y - b2) / k2);
      }
      */
      X0 = X;
      Y0 = Y;

      X = X + dx;
      Y = Y + dy;
      //X0 
    }
    else if (bombDir == "COLDER")
    {
      /*
      int dx = (X - X0);
      int dy = (Y - Y0);

      int x1 = X0;
      int y1 = Y0;
      int x2 = X;
      int y2 = Y;

      double k1 = (y2 - y1) / (x2 - x1);
      double b1 = (x2 * y1 - x1 * y2) / (x2 - x1);

      double k2 = -1 / k1;
      double b2 = y2 + k2 * x2;


      for (int i = 0; i < W; ++i)
      {
        if (i != 0)
        {
          std::cerr << ", ";
        }
        std::cerr << "y" << i << "=" << std::ceil(k2 * i + b2);
      }
      std::cerr << std::endl;
      */
      X = X0;
      Y = Y0;
    }
    else//SAME 
    {

    }
    std::cout << X << " " << Y << std::endl;
  }
}