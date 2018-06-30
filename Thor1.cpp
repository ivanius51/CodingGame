#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
 

 
template <typename T> int sign(T value)
{
  return (value > 0) ? 1 : ((value < 0) ? -1 : 0);
};

/* 
struct Point 
{
    int x, y;
    Point(int x=0, int y=0) 
        : x(x), y(y)
    {
    }
    bool operator==(const Point& point) const
    {
        return (x == point.x && y == point.y);
    }
    Point operator+(const Point& point) const
    {
        return Point(point.x+x, point.y+y);
    }
    Point& operator+=(const Point& point) 
    {
        this->x += point.x;
        this->y += point.y;
        return *this;
    }
    Point operator-(const Point& point) const
    {
        return Point(point.x-x, point.y-y);
    }
    Point& operator-=(const Point& point) 
    {
        this->x -= point.x;
        this->y -= point.y;
        return *this;
    }
};
 
Point getMoveDirection(Point& position)
{
    Point result = {sign(position.x),sign(position.y)};
    return result;
}
 
char* getCardinalDirection(Point& direction)
{
    if (direction.x == 0)
    {
        if (direction.y <0)
            return "N";
        else
            return "S";
    }
    else
    if (direction.y == 0)
    {
        if (direction.x <0)
            return "W";
        else
            return "E";
    }
    else
    {
        
    }
}

*/

char* getCardinalDirection(int directionX, int directionY)
{
    char* result;
    
    if ((directionX == 0) || (directionY == 0))
        result = new char[2];
    else
        result = new char[3];

    int index = 0;
    if (directionY != 0)
    {
        if (directionY < 0)
            result[index] = 'N';
        else
            result[index] = 'S';
        ++index;
    }
    
    if (directionX != 0)
    {
        if (directionX < 0)
            result[index] = 'W';
        else
            result[index] = 'E';
        ++index; 
    }
    ++index; 
    result[index] = 0;         
    return result;
}
 
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
    
    //Point thorPosition = {initialTX, initialTY};
    //Point targetPosititon = {lightX, lightY};
    //Point moves = thorPosition - targetPosititon;
          
    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        int movesX = lightX - initialTX;
        int movesY = lightY - initialTY;
        initialTX += sign(movesX);
        initialTY += sign(movesY);
        
        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout << getCardinalDirection(movesX, movesY) << endl;
        
        //moves -= getMoveDirection(moves);
        
        cerr << "X=" << movesX << endl;
        cerr << "Y=" << movesY << endl;
    }
}