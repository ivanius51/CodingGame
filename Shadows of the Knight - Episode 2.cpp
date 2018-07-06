#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

template <typename T> int sign(T value)
{
  return (value > 0) ? 1 : ((value < 0) ? -1 : 0);
};

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
  int X0, Y0, X, Y;
  std::cin >> X0 >> Y0; std::cin.ignore();

  int minX = 0;
  int minY = 0;
  int maxX = W - 1;
  int maxY = H - 1;

  //std::vector<>

  // game loop
  while (1)
  {
    std::string bombDir; // Current distance to the bomb compared to previous distance (COLDER, WARMER, SAME or UNKNOWN)
    std::cin >> bombDir; std::cin.ignore();

    std::cerr << bombDir << std::endl;

    if (bombDir == "UNKNOWN")
    {
      int dx = (W - X0);
      int dy = (H - Y0);

      std::cerr << W << " " << H << std::endl;

      X = X0;
      Y = Y0;
      if (W == H)
      {
        if (dx > dy)
          X = W / 2;
        else
          Y = H / 2;
      }
      else if (W > H)
      {
        X = W / 2;
      }
      else
      {
        Y = H / 2;
      }
      //std::cout << X << " " << Y << std::endl;
    }
    else if (bombDir == "WARMER")
    {
      int dx = (X - X0);
      int dy = (Y - Y0);

      if (dx != 0)
      {
        if (dx > 0)
        {
          minX = std::max(X - ((dx - 1) / 2), minX);
        }
        else
        {
          maxX = std::min(X - ((dx + 1) / 2), maxX);
        }
      }
      if (dy != 0)
      {
        if (dy > 0)
        {
          minY = std::max(Y - ((dy - 1) / 2), minY);
        }
        else
        {
          maxY = std::min(Y - ((dy + 1) / 2), maxY);
        }
      }

      std::cerr << dx << " " << dy << std::endl;

      X0 = X;
      Y0 = Y;

      if (minY == maxY || minX == maxX)
      {
        std::cerr << "same" << std::endl;
        if (minX == maxX)
        {
          X = minX;
          Y = (minY + (maxY - minY) / 2) + 1;
          if (Y == Y0)
            Y = std::max(Y - 2, minY);
        }
        if (minY == maxY)
        {
          Y = minY;
          X = (minX + (maxX - minX) / 2) + 1;
          if (X == X0)
            X = std::max(X - 2, minX);
        }
      }
      else if ((maxX - minX) >  (maxY - minY))
      {
        {
          X = (minX + (maxX - minX) / 2) + (1 * (X < minX ? 1 :(X <= maxX ? 1 : -1)));
        }
        if (X <= X0)
        {
          std::cerr << "same X" << std::endl;
          X = std::max((minX + (maxX - minX) / 2) + (1 * (X < minX ? 1 : (X <= maxX ? -1 : 1))), minX);
          if (X == X0)
          {
            X = std::min(X + 1, maxX);
          }
        }
      }
      else
      {
        {
          Y = (minY + (maxY - minY) / 2) + (1 * (Y < minY ? 1 : (Y <= maxY ? 1 : -1)));
        }
        if (Y <= Y0)
        {
          std::cerr << "same Y" << std::endl;
          Y = std::max((minY + (maxY - minY) / 2) + (1 * (Y < minY ? 1 : (Y <= maxY ? -1 : 1))), minY);
          if (Y == Y0)
          {
            std::cerr << "same Y" << std::endl;
            Y = std::min(Y + 1, maxY);
          }
        }
      }
    }
    else if (bombDir == "COLDER")
    {
      int dx = (X - X0);
      int dy = (Y - Y0);

      std::cerr << dx << " " << dy << std::endl;

      if (dx != 0)
      {
        if (dx < 0)
        {
          minX = std::max(X - ((dx - 1) / 2), minX);
        }
        else
        {
          maxX = std::min(X - ((dx + 1) / 2), maxX);
        }
      }
      if (dy != 0)
      {
        if (dy < 0)
        {
          minY = std::max(Y - ((dy - 1) / 2), minY);
        }
        else
        {
          maxY = std::min(Y - ((dy + 1) / 2), maxY);
        }
      }

      if (minY == maxY || minX == maxX)
      {
        std::cerr << "same" << std::endl;
        if (minX == maxX)
        {
          X = minX;
        }
        else
          X = (minX + (maxX - minX) / 2) + 1;

        if (minY == maxY)
        {
          Y = minY;
        }
        else
          Y = (minY + (maxY - minY) / 2) + 1;
      }
      else if (dx > dy)
      {
        X0 = X;
        Y0 = Y;
        X = (minX + (maxX - minX) / 2) - (1 * (X <= minX ? 1 : (X <= maxX ? -1 : 1)));
        if (X <= X0)
        {
          std::cerr << "same X" << std::endl;
          X = std::max((minX + (maxX - minX) / 2) - (1 * (X <= minX ? 1 : (X <= maxX ? 1 : -1))), minX); //std::max(X - 2, minX);
          if (X == X0)
          {
            X = std::min(X + 1, maxX);
          }
        }
      }
      else
      {
        X0 = X;
        Y0 = Y;
        Y = (minY + (maxY - minY) / 2) - (1 * (Y <= minY ? 1 : (Y <= maxY ? -1 : 1)));
        if (Y <= Y0)
        {
          std::cerr << "same Y" << std::endl;
          Y = std::max((minY + (maxY - minY) / 2) - (1 * (Y <= minY ? 1 : (Y <= maxY ? 1 : -1))), minY); //std::max(Y - 2, minY);
          if (Y == Y0)
          {
            Y = std::min(Y + 1, maxY);
          }
        }
      }
    }
    else//SAME 
    {
      int dx = (X - X0);
      int dy = (Y - Y0);

      std::cerr << dx << " " << dy << std::endl;

      if (dx != 0)
      {
        minX = X0 + (dx / 2);
        maxX = X - (dx / 2);
      }
      if (dy != 0)
      {
        minY = Y0 + (dy / 2);
        maxY = Y - (dy / 2);
      }

      X0 = X;
      Y0 = Y;
      if (minY == maxY || minX == maxX)
      {
        std::cerr << "SAME same" << std::endl;
        if (minX == maxX)
        {
          X = minX;
        }
        else
          X = (minX + (maxX - minX) / 2) + 1;
        if (minY == maxY)
        {
          Y = minY;
        }
        else
          Y = (minY + (maxY - minY) / 2) + 1;
      }
      else if (dx > dy)
        Y = minY + (maxY - minY) / 2;
      else
        X = minX + (maxX - minX) / 2;
    }

    std::cerr << minX << "," << minY << " " << maxX << "," << maxY << std::endl;

    std::cout << X << " " << Y << std::endl;
  }
}