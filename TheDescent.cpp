#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/
int main()
{

    std::vector<int> mountains;
    
    // game loop
    while (1) 
    {
        mountains.erase(mountains.begin(),mountains.end());
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH; cin.ignore();
            mountains.push_back(mountainH);
        }
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        //int highterMountainIndex = -1;
        //int highterMountainValue = -1;
        
        //for (auto it = mountains.begin(); it != mountains.end(); ++it)
        //{
        //    if (highterMountainValue<*it)
        //    {
        //        highterMountainValue = *it;
        //        highterMountainIndex = std::distance(mountains.begin(), it);
        //    }            
        //}            
        //cout << highterMountainIndex << endl; // The index of the mountain to fire on.
        cout << std::distance(mountains.begin(),std::max_element( mountains.begin(), mountains.end() )) << endl; // The index of the mountain to fire on.
    }
}