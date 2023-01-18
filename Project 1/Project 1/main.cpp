#include "Game.h"
#include "Arena.h"
#include "History.h"
#include "Player.h"
#include "Rabbit.h"
#include "globals.h"
#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;

int main()
{
      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 5, 2);
    Game g(10, 12, 40);

      // Play the game
    g.play();
}
