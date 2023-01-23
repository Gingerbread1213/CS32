//
//  Set.hpp
//  Homework1
//
//  Created by 刘豪杰 on 1/20/23.
//

#ifndef newSet_h
#define newSet_h

#include <iostream>

using ItemType = std::string;


class newSet
{
  public:
    newSet();         // Create an empty set (i.e., one whose size() is 0).
    
    ~newSet();
    
    newSet(int max);
    
    bool empty();  // Return true if the set is empty, otherwise false.

    int size();    // Return the number of items in the set.

    bool insert(const ItemType& value);
      // Insert value into the set if it is not already present.  Return
      // true if the value is actually inserted.  Leave the set unchanged
      // and return false if value is not inserted (perhaps because it
      // was already in the set or because the set has a fixed capacity and
      // is full).

    bool erase(const ItemType& value);
      // Remove the value from the set if it is present.  Return true if the
      // value was removed; otherwise, leave the set unchanged and
      // return false.
     
    bool contains(const ItemType& value);
      // Return true if the value is in the set, otherwise false.
     
    bool get(int i, ItemType& value);
      // If 0 <= i < size(), copy into value the item in the set that is
      // strictly greater than exactly i items in the set and return true.
      // Otherwise, leave value unchanged and return false.

    void swap(newSet& other);
      // Exchange the contents of this set with the other one.
    void read();
private:
    int length=0;
    int max;
    ItemType *container;
    
};

#endif /* Set_hpp */
