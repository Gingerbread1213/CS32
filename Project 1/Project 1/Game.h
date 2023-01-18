//
//  Game.hpp
//  Project 1
//
//  Created by 刘豪杰 on 1/17/23.
//

#ifndef Game_hpp
#define Game_hpp

#include <string>


using namespace std;

class Arena;


class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nRabbits);
    ~Game();

      // Mutators
    void play();

  private:
    Arena* m_arena;

      // Helper functions
    string takePlayerTurn();
};

#endif /* Game_hpp */
