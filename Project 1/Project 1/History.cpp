//
//  History.cpp
//  Project 1
//
//  Created by 刘豪杰 on 1/17/23.
//

#include "History.h"
#include <iostream>

using namespace std;

History:: History(int nRows, int nCols){
    
    rows = nRows;
    cols = nCols;
    
    for(int i=0; i<nRows; i++){
        
        for (int j=0; j<nCols; j++){
            board[i][j]=1; //form a board contains 0
            cBoard[i][j]='.';// form a board contains '.'
        }
    }
    
}
bool History::record(int r, int c){
    //see if the board is out of bound
    if (r<1){
        return false;
    }
    else if (r>MAXROWS){
        return false;
    }
    else if (c<1){
        return false;
    }
    else if(c>MAXCOLS){
        return false;
    }
    if(board[r-1][c-1]>=26){
        cBoard[r-1][c-1]='Z';
        return true;
    }
    char x[26]={'.','A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    cBoard[r-1][c-1]=x[board[r-1][c-1]];
    board[r-1][c-1]++;
    
        
    
    
    return true;
    
}
void History::display() const{
    clearScreen();

    for (int i =0; i<rows; i++){
        for (int j=0; j<cols; j++){
            cout << cBoard[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
