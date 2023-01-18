//
//  Arena.hpp
//  Project 1
//
//  Created by 刘豪杰 on 1/17/23.
//

#ifndef Arena_hpp
#define Arena_hpp


#include <string>
#include "History.h"
#include "globals.h"




using namespace std;

class Rabbit;
class Player;
class History;

class Arena
{
  public:
      // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();

      // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     rabbitCount() const;
    int     getCellStatus(int r, int c) const;
    int     numberOfRabbitsAt(int r, int c) const;
    void    display(string msg) const;


      // Mutators
    void setCellStatus(int r, int c, int status);
    bool addRabbit(int r, int c);
    bool addPlayer(int r, int c);
    void moveRabbits();
    History& history();
    
  private:
    int     m_grid[20][25];
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Rabbit* m_rabbits[100];
    History* m_history;
    int     m_nRabbits;
    int     m_turns;

      // Helper functions
    void checkPos(int r, int c, string functionName) const;
    bool isPosInBounds(int r, int c) const;
};


#endif /* Arena_hpp */
