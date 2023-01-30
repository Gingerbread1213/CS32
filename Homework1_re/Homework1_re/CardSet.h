//
//  CardSet.cpp
//  Homework1
//
//  Created by 刘豪杰 on 1/22/23.
//
#include "Set.h"
#include "CardSet.h"

using namespace std;

CardSet::CardSet(){
    
}      // Create an empty card set.

bool CardSet::add(unsigned long cardNumber){
    
    if(cardNumber<0){
        return false;
    }
    else{
        card.insert(cardNumber);
        cards[num] = cardNumber;
        num = card.size();
        return true;
    }
    
    
    return false;
}
  // Add a card number to the CardSet.  Return true if and only if the
  // card number was actually added.

int CardSet::size() const{
    
    
    return num;
    
}  // Return the number of card numbers in the CardSet.

void CardSet::print() const{
    if(size()==0){
        
        return;
        
    }
    else{
        for (int i =0; i<num; i++){
            cout << cards[i] << endl;
        }
        
    }
    return;
    
}


