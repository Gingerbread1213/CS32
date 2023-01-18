//
//  History.hpp
//  Project 1
//
//  Created by 刘豪杰 on 1/17/23.
//

#ifndef History_hpp
#define History_hpp

#include "globals.h"
class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int rows, cols;
    int board[20][25];
    char cBoard[20][25];
    
};
#endif /* History_hpp */
