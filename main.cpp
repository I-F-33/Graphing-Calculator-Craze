#include <iostream>
#include "includes/sfml/animate.h"
using namespace std;

int main()
{
    animate game;
    game.run();
    cout << endl
         << endl
         << "------ MAIN EXITING --------------------------" << endl;
    return 0;
}
