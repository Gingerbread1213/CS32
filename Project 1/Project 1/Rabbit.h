//
//  Rabbit.hpp
//  Project 1
//
//  Created by 刘豪杰 on 1/17/23.
//

#ifndef Rabbit_hpp
#define Rabbit_hpp



class Arena;  // This is needed to let the compiler know that Arena is a
              // type name, since it's mentioned in the Rabbit declaration.

class Rabbit
{
  public:
      // Constructor
    Rabbit(Arena* ap, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;
    

      // Mutators
    void move();
    
  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
    int    m_idleTurnsRemaining;
};


#endif /* Rabbit_hpp */
