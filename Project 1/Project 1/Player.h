//
//  Player.hpp
//  Project 1
//
//  Created by 刘豪杰 on 1/17/23.
//

#ifndef Player_hpp
#define Player_hpp


#include <string>
#include "globals.h"


using namespace std;



class Player
{
  public:
      // Constructor
    Player(Arena* ap, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

      // Mutators
    string dropPoisonedCarrot();
    string move(int dir);
    void   setDead();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    bool   m_dead;
};

#endif /* Player_hpp */
